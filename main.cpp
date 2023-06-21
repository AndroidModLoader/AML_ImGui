#include <mod/amlmod.h>
#include <mod/logger.h>

#include <string>
#include "main.h"
#include "arial.h"

MYMOD(net.rusjj.imgui, DearImGui, 1.0.0, ocornut & RusJJ)

static IM imgui;
IImGui* pImGui = &imgui;
ImGuiContext *imguiCtx = NULL;

static const ImWchar ranges[] = {
    0x0020, 0x0080,
    0x00A0, 0x00C0,
    0x0400, 0x0460,
    0x0490, 0x04A0,
    0x2010, 0x2040,
    0x20A0, 0x20B0,
    0x2110, 0x2130,
    0                           };

uintptr_t pGameLib = 0;
void* pGameHandle = nullptr;
eGTA nLoadedGTA = WRONG;
bool bImGuiInitialized = false;

RwReal* nearScreenZ;
RwReal* recipNearClip;
void* pTheCamera = nullptr;
void (*SetScissorRect)(float*) = nullptr;
int (*GetScreenFadeStatus)(void*) = nullptr;
int* m_bMenuOpened;
bool* m_UserPause;

ImVec2 displaySize;
ImVec2 zeroVec(0,0);

static float flScaleX, flScaleY;
static int nDisplayX, nDisplayY;
inline float ScaleX(float x) { return flScaleX * x; } float IM::GetScaledX(float f) { return ScaleX(f); }
inline float ScaleY(float y) { return flScaleY * y; } float IM::GetScaledY(float f) { return ScaleY(f); }
int IM::GetScreenSizeX() { return nDisplayX; }
int IM::GetScreenSizeY() { return nDisplayY; }

void ImGui_ImplRenderWare_RenderDrawData(ImDrawData* draw_data);
bool ImGui_ImplRenderWare_Init();
void ImGui_ImplRenderWare_NewFrame();
void ImGui_ImplRenderWare_ShutDown();

#define FRAMES_TO_CLEAR_MOUSE 3
static char nClearMousePos = 0;
ImFont* kbFont;
DECL_HOOK(bool, InitRenderware)
{
    if(!InitRenderware()) return false;
    InitRenderWareFunctions();

    // Main
    nDisplayX = RsGlobal->maximumWidth;
    nDisplayY = RsGlobal->maximumHeight;
    flScaleX = nDisplayY * 0.00052083333f; // 1/1920
    flScaleY = nDisplayY * 0.00092592592f; // 1/1080
    displaySize.x = nDisplayX;
    displaySize.y = nDisplayY;
    bImGuiInitialized = true;

    // Main context
    imguiCtx = ImGui::CreateContext();
    ImGui_ImplRenderWare_Init();
    ImGuiIO &io = ImGui::GetIO();
    ImGuiStyle& style = ImGui::GetStyle();
    style.ScrollbarSize = ScaleY(55.0f);
    style.WindowBorderSize = 0.0f;
    ImGui::StyleColorsDark();
    imgui.m_pFont = io.Fonts->AddFontFromMemoryTTF((void*)arialData, sizeof(arialData), ScaleY(34.0f), NULL, ranges);

    return true;
}
DECL_HOOKv(ShutdownRenderware)
{
    ImGui_ImplRenderWare_ShutDown();
    ImGui::DestroyContext();
    ShutdownRenderware();
}
bool bDisplaySpecialImGuiMenu = false;
ImGuiID LastFocus = -1, LastActive = -1;
ImGuiWindow* LastWindow;
inline void KeyboardButton(ImGuiIO& io, const char* text, const char actualKey)
{
    if (ImGui::Button(text, ImVec2(ScaleX(actualKey==' '?750.0f:250.0f), ScaleX(160.0f))))
    {
        ImGui::SetFocusID(LastFocus, LastWindow);
        ImGui::SetActiveID(LastActive, LastWindow);
        io.AddInputCharacter(actualKey);
    }
}
inline bool KeyboardButtonNaked(const char* text)
{
    return (ImGui::Button(text, ImVec2(ScaleX(250.0f), ScaleX(160.0f))));
}
inline void RestoreFocus()
{
    ImGui::SetFocusID(LastFocus, LastWindow);
    ImGui::SetActiveID(LastActive, LastWindow);
}
int language = 0;
bool shift = false;
inline const char* GetLineChars(unsigned char line)
{
    switch(language)
    {
        case 0:
        {
            switch(line)
            {
                case 1: return shift ? "~!@#$%^&*()_+" : "`1234567890-=";
                case 2: return shift ? "QWERTYUIOP{}|" : "qwertyuiop[]\\";
                case 3: return shift ? "ASDFGHJKL:\"" : "asdfghjkl;'";
                case 4: return shift ? "ZXCVBNM<>?" : "zxcvbnm,./";
            }
            break;
        }
        case 1:
        {
            switch(line)
            {
                case 1: return shift ? "Ё!\"№;%:?*()_+" : "ё1234567890-=";
                case 2: return shift ? "ЙЦУКЕНГШЩЗХЪ\\" : "йцукенгшщзхъ\\";
                case 3: return shift ? "ФЫВАПРОЛДЖЭ" : "фывапролджэ";
                case 4: return shift ? "ЯЧСМИТЬБЮ," : "ячсмитьбю.";
            }
            break;
        }
    }
    return "";
}
DECL_HOOKv(Render2DStuff)
{
    Render2DStuff();

    ImGui_ImplRenderWare_NewFrame(); 
    ImGui::NewFrame();
    ImGuiIO& io = ImGui::GetIO();

    // ImGui's mod special window START
    if(bDisplaySpecialImGuiMenu)
    {
        ImGui::SetNextWindowBgAlpha(0.82f);
        ImGui::Begin("ImGuiMenu", NULL, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
        ImGui::SetWindowSize(displaySize);
        ImGui::SetWindowPos(zeroVec, true);
        ImVec2 av = ImGui::GetContentRegionAvail();
        float padding = av.x * 0.018f;
        ImGui::SetNextWindowPos(ImVec2(padding, padding));
        if(ImGui::BeginChild("ImGuiMenuChild", ImVec2((float)nDisplayX - 2.0f * padding, av.y - padding), true))
        {
            auto end = imgui.m_pMenuRenderListeners.end();
            for (auto it = imgui.m_pMenuRenderListeners.begin(); it != end; ++it)
            {
                if(*it != NULL)
                {
                    ((void(*)())(*it))();
                    pImGui->Separator();
                }
            }
            ImGui::EndChild();
        }
        ImGui::End();
    }
    // ImGui's mod special window END

    // Render from mods START
    if(!bDisplaySpecialImGuiMenu)
    {
        auto end = imgui.m_pRenderListeners.end();
        for (auto it = imgui.m_pRenderListeners.begin(); it != end; ++it)
        {
            if(*it != NULL) ((void(*)())(*it))();
        }
    }
    // Render from mods END

    // Our button should be the latest! Always visible and always clickable!
    ImGui::SetNextWindowBgAlpha(0.0f);
    ImGui::Begin("ImGuiMenuButton", NULL, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
    auto CheckboxWindow = ImGui::GetCurrentWindow();
    ImGui::SetWindowPos({displaySize.x - 1.25f * ImGui::GetWindowWidth(), displaySize.y - ImGui::GetWindowHeight()}, true);
    ImGui::Checkbox("ImGui Menu", &bDisplaySpecialImGuiMenu);
    ImGui::End();

    /* KEYBOARD */
    ImGui::BringWindowToDisplayFront(CheckboxWindow);
    if(io.WantTextInput || LastFocus != -1)
    {
        if(LastFocus == -1)
        {
            LastWindow = imguiCtx->NavWindow;
            LastFocus = ImGui::GetFocusID();
            LastActive = ImGui::GetActiveID();
        }

        ImGui::SetNextWindowBgAlpha(0.82f);
        ImGui::Begin("ImGuiKeyboard", NULL, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);

        io.KeysDown[ImGuiKey_Backspace] = false;
        auto KeyboardLine = [&io](const char* k)
        {
            size_t num = strlen(k), num1 = num - 1;
            for (size_t i = 0; i < num; i++)
            {
                char key_label[4] {0};
                key_label[0] = *k;
                if((unsigned char)(*k) > 0xBF)
                {
                    ++i;
                    key_label[1] = *(++k);
                    KeyboardButton(io, key_label, *(k - 1));
                }
                else KeyboardButton(io, key_label, *k);
                ++k;
                if (i < num1) ImGui::SameLine();
            }
        };

        // Line 1
        KeyboardLine(GetLineChars(1));
        ImGui::SameLine();
        if(KeyboardButtonNaked("Del"))
        {
            RestoreFocus();
            io.KeysDown[ImGuiKey_Backspace] = true;
        }

        // Line 2
        KeyboardButton(io, "TAB", '\t'); // ImGuiKey_Tab
        ImGui::SameLine();
        KeyboardLine(GetLineChars(2));

        // Line 3
        if(KeyboardButtonNaked("CAPS"))
        {
            RestoreFocus();
            shift = !shift;
        }
        ImGui::SameLine();
        KeyboardLine(GetLineChars(3));

        // Line 4
        if(KeyboardButtonNaked(language == 0 ? "ENG" : "РУС"))
        {
            RestoreFocus();
            language = !language;
        }
        ImGui::SameLine();
        KeyboardLine(GetLineChars(4));

        // Line 5
        if(KeyboardButtonNaked("x")) LastFocus = -1;
        ImGui::SameLine();
        ImGui::Text("                                                        ");
        ImGui::SameLine();
        KeyboardButton(io, "SPACE", ' ');

        ImGui::SetWindowPos({0, displaySize.y - ImGui::GetWindowHeight()}, true);
        ImGui::SetWindowSize({displaySize.x, 0});
        ImGui::BringWindowToDisplayFront(ImGui::GetCurrentWindow());
        ImGui::End();
        // Render the data
    }
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplRenderWare_RenderDrawData(ImGui::GetDrawData());
    /* KEYBOARD END */

    if(nClearMousePos > 0)
    {
        if(--nClearMousePos == 0)
        {
            io.AddMousePosEvent(-FLT_MAX, -FLT_MAX);
        }
    }
}

static uint8_t fingers = 0;
static uint8_t fingerAsMouse = 0xFF;
static bool g_bIgnoredFingers[10] = {false}; // 10 just to be sure.
inline bool CanProcessImTouch()
{
    return (bImGuiInitialized && *m_bMenuOpened == 0 && *m_UserPause == false && GetScreenFadeStatus(pTheCamera) != 2);
}
inline bool NeedToIgnore()
{
    return bDisplaySpecialImGuiMenu || ImGui::IsAnyItemHovered(); //false;//ImGui::GetIO().WantCaptureMouse; || ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow | ImGuiHoveredFlags_RectOnly);
}
DECL_HOOKv(OnTouchEvent, int type, int fingerId, int x, int y)
{
    ImGuiIO* io = &ImGui::GetIO();

    bool canProc = CanProcessImTouch();
    if(type == TOUCH_PUSH) ++fingers;
    else if(type == TOUCH_RELEASE) --fingers;
    
    if(!canProc)
    {
        OnTouchEvent(type, fingerId, x, y);
        return;
    }
    
    switch(type)
    {
        case TOUCH_PUSH:
        {
            if(fingerAsMouse == 0xFF)
            {
                io->AddMousePosEvent(x, y);
                io->AddMouseButtonEvent(0, true);
                
                fingerAsMouse = fingerId;
            }
            
            if(NeedToIgnore())
            {
                g_bIgnoredFingers[fingerId] = true;
            }
            else
            {
                OnTouchEvent(type, fingerId, x, y);
            }
            break;
        }
        
        case TOUCH_RELEASE:
        {
            if(fingerAsMouse == fingerId)
            {
                nClearMousePos = FRAMES_TO_CLEAR_MOUSE;
                io->AddMouseButtonEvent(0, false);
                
                fingerAsMouse = 0xFF;
            }
            
            if(!g_bIgnoredFingers[fingerId]) OnTouchEvent(type, fingerId, x, y);
            g_bIgnoredFingers[fingerId] = false;
            break;
        }
        
        case TOUCH_MOVE:
        {
            if(fingerAsMouse == fingerId)
            {
                io->AddMousePosEvent(x, y);
            }
            
            if(!g_bIgnoredFingers[fingerId]) OnTouchEvent(type, fingerId, x, y);
            break;
        }
        
        // whatever...
        default:
        {
            OnTouchEvent(type, fingerId, x, y);
            break;
        }
    }
}

extern "C" void OnModPreLoad()
{
    logger->SetTag("Dear ImGui");
    pGameLib = aml->GetLib("libGTASA.so");
    if(pGameLib)
    {
        pGameHandle = aml->GetLibHandle("libGTASA.so");
        nLoadedGTA = GTASA;
    }
    else
    {
        pGameLib = aml->GetLib("libGTAVC.so");
        if(pGameLib)
        {
            // Not working
            pGameHandle = aml->GetLibHandle("libGTAVC.so");
            nLoadedGTA = GTAVC;
        }
        else
        {
            logger->Error("Cannot determine a game library!");
            return;
        }
    }
    SET_TO(nearScreenZ, aml->GetSym(pGameHandle, "_ZN9CSprite2d11NearScreenZE"));
    SET_TO(recipNearClip, aml->GetSym(pGameHandle, "_ZN9CSprite2d13RecipNearClipE"));
    SET_TO(SetScissorRect, aml->GetSym(pGameHandle, "_ZN7CWidget10SetScissorER5CRect"));
    SET_TO(GetScreenFadeStatus, aml->GetSym(pGameHandle, "_ZN7CCamera19GetScreenFadeStatusEv"));
    SET_TO(pTheCamera, aml->GetSym(pGameHandle, "TheCamera"));

    RegisterInterface("ImGui", pImGui);
}

extern "C" void OnModLoad()
{
    if(!pGameLib) return;
    if(nLoadedGTA == GTASA) // For some reason i need to hook PLT, crash. Something is broken in Substrate or... the game?
    {
        HOOKPLT(InitRenderware, pGameLib + 0x66F2D0);
        HOOKPLT(OnTouchEvent, pGameLib + 0x675DE4);
        SET_TO(m_bMenuOpened, pGameLib + 0x6E0098);
        SET_TO(m_UserPause, aml->GetSym(pGameHandle, "_ZN6CTimer11m_UserPauseE"));
    }
    else
    {
        if(nLoadedGTA == GTAVC) m_bMenuOpened = (int*)(pGameLib + 0x5A9A40);
        HOOK(InitRenderware, aml->GetSym(pGameHandle, "_ZN5CGame20InitialiseRenderWareEv"));
        HOOK(OnTouchEvent, aml->GetSym(pGameHandle, "_Z14AND_TouchEventiiii"));
    }
    HOOK(Render2DStuff, aml->GetSym(pGameHandle, "_Z13Render2dStuffv"));
}