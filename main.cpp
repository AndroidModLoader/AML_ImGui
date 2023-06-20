#include <mod/amlmod.h>
#include <mod/logger.h>

#include "main.h"
#include "arial.h"

MYMOD(net.rusjj.imgui, DearImGui, 1.0.0, ocornut & RusJJ)

static IM imgui;
IImGui* pImGui = &imgui;
ImGuiContext* imguiCtx = nullptr;

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
DECL_HOOK(bool, InitRenderware)
{
    if(!InitRenderware()) return false;

    InitRenderWareFunctions();
    imguiCtx = ImGui::CreateContext();
    ImGui_ImplRenderWare_Init();
    ImGuiIO &io = ImGui::GetIO();
    ImGuiStyle& style = ImGui::GetStyle();

    nDisplayX = RsGlobal->maximumWidth;
    nDisplayY = RsGlobal->maximumHeight;
    flScaleX = io.DisplaySize.x * 0.00052083333f; // 1/1920
    flScaleY = io.DisplaySize.y * 0.00092592592f; // 1/1080
    style.ScrollbarSize = ScaleY(55.0f);
    style.WindowBorderSize = 0.0f;
    ImGui::StyleColorsDark();

    imgui.m_pFont = io.Fonts->AddFontFromMemoryTTF((void*)arialData, sizeof(arialData), ScaleY(30.0f), nullptr, ranges);

    displaySize.x = nDisplayX;
    displaySize.y = nDisplayY;
    bImGuiInitialized = true;
    return true;
}
DECL_HOOKv(ShutdownRenderware)
{
    ImGui_ImplRenderWare_ShutDown();
    ImGui::DestroyContext();
    ShutdownRenderware();
}
bool bDisplaySpecialImGuiMenu = false, bAlwaysShow = false;
DECL_HOOKv(Render2DStuff)
{
    Render2DStuff();

    ImGui_ImplRenderWare_NewFrame(); 
    ImGui::NewFrame();
    ImGuiIO& io = ImGui::GetIO();

    // ImGui's mod special window START
    ImGui::SetNextWindowBgAlpha(bDisplaySpecialImGuiMenu ? 0.82f : 0.0f);
    ImGui::Begin("ImGuiMenu", NULL, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
    ImGui::SetWindowPos(zeroVec);
    ImGui::SetCursorPosX(0.5f * nDisplayX);
    ImGui::Checkbox("ImGui Menu", &bDisplaySpecialImGuiMenu);
    if(bDisplaySpecialImGuiMenu || bAlwaysShow)
    {
        ImGui::SetWindowSize(displaySize);
        //ImGui::SameLine();
        //ImGui::SetCursorPosX(0.666f * nDisplayX);
        //ImGui::Checkbox("Show Always", &bAlwaysShow);
        //ImGui::NewLine();
        ImVec2 av = ImGui::GetContentRegionAvail();
        float padding = av.x * 0.04f;
        float twopadding = 2.0f * padding;
        ImGui::SetNextWindowPos(ImVec2(padding, padding));
        if(ImGui::BeginChild("ImGuiMenuChild", ImVec2((float)nDisplayX - twopadding, av.y - padding), true))
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
    } else ImGui::SetWindowSize(zeroVec);
    ImGui::End();
    // ImGui's mod special window END

    // Render from mods START
    if(!bDisplaySpecialImGuiMenu && !bAlwaysShow)
    {
        auto end = imgui.m_pRenderListeners.end();
        for (auto it = imgui.m_pRenderListeners.begin(); it != end; ++it)
        {
            if(*it != NULL) ((void(*)())(*it))();
        }
    }
    // Render from mods END
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplRenderWare_RenderDrawData(ImGui::GetDrawData());

    if(nClearMousePos > 0)
    {
        //io.MousePos.x = io.MousePos.y = -1;
        if(--nClearMousePos == 0) io.AddMousePosEvent(-FLT_MAX, -FLT_MAX);
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
    bool canProc = CanProcessImTouch();
    if(type == TOUCH_PUSH) ++fingers;
    else if(type == TOUCH_RELEASE) --fingers;
    
    if(!canProc)
    {
        OnTouchEvent(type, fingerId, x, y);
        return;
    }
    ImGuiIO& io = ImGui::GetIO();
    switch(type)
    {
        case TOUCH_PUSH:
        {
            if(fingerAsMouse == 0xFF)
            {
                //io.MousePos = ImVec2(x, y);
                //io.MouseDown[0] = true;
                io.AddMousePosEvent(x, y);
                io.AddMouseButtonEvent(0, true);
                
                fingerAsMouse = fingerId;
            }
            
            //ImGui::UpdateHoveredWindowAndCaptureFlags();
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
                //io.MouseDown[0] = false;
                io.AddMouseButtonEvent(0, false);
                
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
                //io.MousePos = ImVec2(x, y);
                //ImGui::UpdateHoveredWindowAndCaptureFlags();
                io.AddMousePosEvent(x, y);
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