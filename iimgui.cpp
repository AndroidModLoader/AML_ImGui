#include "main.h"

ImFont* IM::GetFont()
{
    return m_pFont;
}

void IM::AddRenderListener(void* fn)
{
    m_pRenderListeners.push_back(fn);
}

bool IM::RemoveRenderListener(void* fn)
{
    auto end = m_pRenderListeners.end();
    for (auto it = m_pRenderListeners.begin(); it != end; ++it)
    {
        if(*it == fn)
        {
            m_pRenderListeners.erase(it);
            return true;
        }
    }
    return false;
}

void IM::AddMenuRenderListener(void* fn)
{
    m_pMenuRenderListeners.push_back(fn);
}

bool IM::RemoveMenuRenderListener(void* fn)
{
    auto end = m_pMenuRenderListeners.end();
    for (auto it = m_pMenuRenderListeners.begin(); it != end; ++it)
    {
        if(*it == fn)
        {
            m_pMenuRenderListeners.erase(it);
            return true;
        }
    }
    return false;
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Main /////
//////////////////////////////////////////////////
const char* IM::GetVersion()
{
    return ImGui::GetVersion();
}

int IM::GetVersionNum()
{
    return IMGUI_VERSION_NUM;
}

bool IM::Begin(const char* name, bool* p_open, ImGuiWindowFlags flags)
{
    return ImGui::Begin(name, p_open, flags);
}
void IM::End()
{
    ImGui::End();
}
bool IM::BeginChild(const char* str_id, const ImVec2& size, bool border, ImGuiWindowFlags flags)
{
    return BeginChild(str_id, size, border, flags);
}
bool IM::BeginChild(ImGuiID id, const ImVec2& size, bool border, ImGuiWindowFlags flags)
{
    return BeginChild(id, size, border, flags);
}
void IM::EndChild()
{
    ImGui::EndChild();
}
//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Combos ///
//////////////////////////////////////////////////
bool IM::BeginCombo(const char* label, const char* preview_value, ImGuiComboFlags flags)
{
    return ImGui::BeginCombo(label, preview_value, flags);
}
void IM::EndCombo()
{
    ImGui::EndCombo();
}
bool IM::Combo(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items)
{
    return ImGui::Combo(label, current_item, items, items_count, popup_max_height_in_items);
}
bool IM::Combo(const char* label, int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items)
{
    return ImGui::Combo(label, current_item, items_separated_by_zeros, popup_max_height_in_items);
}
bool IM::Combo(const char* label, int* current_item, bool(*items_getter)(void*, int, const char**), void* data, int items_count, int popup_max_height_in_items)
{
    return IM::Combo(label, current_item, items_getter, data, items_count, popup_max_height_in_items);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Window ///
//////////////////////////////////////////////////
bool IM::IsWindowAppearing()
{
    return ImGui::IsWindowAppearing();
}
bool IM::IsWindowCollapsed()
{
    return ImGui::IsWindowCollapsed();
}
bool IM::IsWindowFocused(ImGuiFocusedFlags flags)
{
    return ImGui::IsWindowFocused(flags);
}
bool IM::IsWindowHovered(ImGuiHoveredFlags flags)
{
    return ImGui::IsWindowHovered(flags);
}
ImVec2 IM::GetWindowPos()
{
    return ImGui::GetWindowPos();
}
ImVec2 IM::GetWindowSize()
{
    return ImGui::GetWindowSize();
}
float IM::GetWindowWidth()
{
    return ImGui::GetWindowWidth();
}
float IM::GetWindowHeight()
{
    return ImGui::GetWindowHeight();
}

//////////////////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Window Manipulation //
//////////////////////////////////////////////////////////////
void IM::SetNextWindowPos(const ImVec2& pos, ImGuiCond cond, const ImVec2& pivot)
{
    ImGui::SetNextWindowPos(pos, cond, pivot);
}
void IM::SetNextWindowSize(const ImVec2& size, ImGuiCond cond)
{
    ImGui::SetNextWindowSize(size, cond);
}
void IM::SetNextWindowSizeConstraints(const ImVec2& size_min, const ImVec2& size_max, ImGuiSizeCallback custom_callback, void* custom_callback_data)
{
    ImGui::SetNextWindowSizeConstraints(size_min, size_max, custom_callback, custom_callback_data);
}
void IM::SetNextWindowContentSize(const ImVec2& size)
{
    ImGui::SetNextWindowContentSize(size);
}
void IM::SetNextWindowCollapsed(bool collapsed, ImGuiCond cond)
{
    ImGui::SetNextWindowCollapsed(collapsed, cond);
}
void IM::SetNextWindowFocus()
{
    ImGui::SetNextWindowFocus();
}
void IM::SetNextWindowBgAlpha(float alpha)
{
    ImGui::SetNextWindowBgAlpha(alpha);
}
void IM::SetWindowPos(const ImVec2& pos, ImGuiCond cond)
{
    ImGui::SetWindowPos(pos, cond);
}
void IM::SetWindowSize(const ImVec2& size, ImGuiCond cond)
{
    ImGui::SetWindowSize(size, cond);
}
void IM::SetWindowCollapsed(bool collapsed, ImGuiCond cond)
{
    ImGui::SetWindowCollapsed(collapsed, cond);
}
void IM::SetWindowFocus()
{
    ImGui::SetWindowFocus();
}
void IM::SetWindowFontScale(float scale)
{
    ImGui::SetWindowFontScale(scale);
}
void IM::SetWindowPos(const char* name, const ImVec2& pos, ImGuiCond cond)
{
    ImGui::SetWindowPos(name, pos, cond);
}
void IM::SetWindowSize(const char* name, const ImVec2& size, ImGuiCond cond)
{
    ImGui::SetWindowSize(name, size, cond);
}
void IM::SetWindowCollapsed(const char* name, bool collapsed, ImGuiCond cond)
{
    ImGui::SetWindowCollapsed(name, collapsed, cond);
}
void IM::SetWindowFocus(const char* name)
{
    ImGui::SetWindowFocus(name);
}

///////////////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Cursor/Layout /////
///////////////////////////////////////////////////////////
void IM::Separator()
{
    ImGui::Separator();
}
void IM::SameLine(float offset_from_start_x, float spacing)
{
    ImGui::SameLine(offset_from_start_x, spacing);
}
void IM::NewLine()
{
    ImGui::NewLine();
}
void IM::Spacing()
{
    ImGui::Spacing();
}
void IM::Dummy(const ImVec2& size)
{
    ImGui::Dummy(size);
}
void IM::Indent(float indent_w)
{
    ImGui::Indent(indent_w);
}
void IM::Unindent(float indent_w)
{
    ImGui::Unindent(indent_w);
}
void IM::BeginGroup()
{
    ImGui::BeginGroup();
}
void IM::EndGroup()
{
    ImGui::EndGroup();
}
ImVec2 IM::GetCursorPos()
{
    return ImGui::GetCursorPos();
}
float IM::GetCursorPosX()
{
    return ImGui::GetCursorPosX();
}
float IM::GetCursorPosY()
{
    return ImGui::GetCursorPosY();
}
void IM::SetCursorPos(const ImVec2& local_pos)
{
    ImGui::SetCursorPos(local_pos);
}
void IM::SetCursorPosX(float local_x)
{
    ImGui::SetCursorPosX(local_x);
}
void IM::SetCursorPosY(float local_y)
{
    ImGui::SetCursorPosY(local_y);
}
ImVec2 IM::GetCursorStartPos()
{
    return ImGui::GetCursorStartPos();
}
ImVec2 IM::GetCursorScreenPos()
{
    return ImGui::GetCursorScreenPos();
}
void IM::SetCursorScreenPos(const ImVec2& pos)
{
    ImGui::SetCursorScreenPos(pos);
}
void IM::AlignTextToFramePadding()
{
    ImGui::AlignTextToFramePadding();
}
float IM::GetTextLineHeight()
{
    return ImGui::GetTextLineHeight();
}
float IM::GetTextLineHeightWithSpacing()
{
    return ImGui::GetTextLineHeightWithSpacing();
}
float IM::GetFrameHeight()
{
    return ImGui::GetFrameHeight();
}
float IM::GetFrameHeightWithSpacing()
{
    return ImGui::GetFrameHeightWithSpacing();
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Text /////
//////////////////////////////////////////////////
void IM::TextUnformatted(const char* text, const char* text_end)
{

}
void IM::Text(const char* fmt, ...)
{
    va_list args;        
    va_start(args, fmt);
    ImGui::TextV(fmt, args);
    va_end(args);
}
void IM::TextV(const char* fmt, va_list args)
{
    ImGui::TextV(fmt, args);
}
void IM::TextColored(const ImVec4& col, const char* fmt, ...)
{
    va_list args;        
    va_start(args, fmt);
    ImGui::TextColoredV(col, fmt, args);
    va_end(args);
}
void IM::TextColoredV(const ImVec4& col, const char* fmt, va_list args)
{
    ImGui::TextColoredV(col, fmt, args);
}
void IM::TextDisabled(const char* fmt, ...)
{
    va_list args;        
    va_start(args, fmt);
    ImGui::TextDisabledV(fmt, args);
    va_end(args);
}
void IM::TextDisabledV(const char* fmt, va_list args)
{
    ImGui::TextDisabledV(fmt, args);
}
void IM::TextWrapped(const char* fmt, ...)
{
    va_list args;        
    va_start(args, fmt);
    ImGui::TextWrappedV(fmt, args);
    va_end(args);
}
void IM::TextWrappedV(const char* fmt, va_list args)
{
    ImGui::TextWrappedV(fmt, args);
}
void IM::LabelText(const char* label, const char* fmt, ...)
{
    va_list args;        
    va_start(args, fmt);
    ImGui::LabelTextV(label, fmt, args);
    va_end(args);
}
void IM::LabelTextV(const char* label, const char* fmt, va_list args)
{
    ImGui::LabelTextV(label, fmt, args);
}
void IM::BulletText(const char* fmt, ...)
{
    va_list args;        
    va_start(args, fmt);
    ImGui::BulletTextV(fmt, args);
    va_end(args);
}
void IM::BulletTextV(const char* fmt, va_list args)
{
    ImGui::BulletTextV(fmt, args);
}
//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Widgets //
//////////////////////////////////////////////////
bool IM::Button(const char* label, const ImVec2& size)
{
    return ImGui::Button(label, size);
}
bool IM::SmallButton(const char* label)
{
    return ImGui::SmallButton(label);
}
bool IM::InvisibleButton(const char* str_id, const ImVec2& size, ImGuiButtonFlags flags)
{
    return ImGui::InvisibleButton(str_id, size, flags);
}
bool IM::ArrowButton(const char* str_id, ImGuiDir dir)
{
    return ImGui::ArrowButton(str_id, dir);
}
void IM::Image(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, const ImVec4& tint_col, const ImVec4& border_col)
{
    ImGui::Image(user_texture_id, size, uv0, uv1, tint_col, border_col);
}
bool IM::ImageButton(const char* str_id, ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, const ImVec4& bg_col, const ImVec4& tint_col)
{
    return ImGui::ImageButton(str_id, user_texture_id, size, uv0, uv1, bg_col, tint_col);
}
bool IM::Checkbox(const char* label, bool* v)
{
    return ImGui::Checkbox(label, v);
}
bool IM::CheckboxFlags(const char* label, int* flags, int flags_value)
{
    return ImGui::CheckboxFlags(label, flags, flags_value);
}
bool IM::CheckboxFlags(const char* label, unsigned int* flags, unsigned int flags_value)
{
    return ImGui::CheckboxFlags(label, flags, flags_value);
}
bool IM::RadioButton(const char* label, bool active)
{
    return ImGui::RadioButton(label, active);
}
bool IM::RadioButton(const char* label, int* v, int v_button)
{
    return ImGui::RadioButton(label, v, v_button);
}
void IM::ProgressBar(float fraction, const ImVec2& size_arg, const char* overlay)
{
    ImGui::ProgressBar(fraction, size_arg, overlay);
}
void IM::Bullet()
{
    ImGui::Bullet();
}

///////////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Drag Slider ///
///////////////////////////////////////////////////////
bool IM::DragFloat(const char* label, float* v, float v_speed, float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, flags);
}
bool IM::DragFloat2(const char* label, float v[2], float v_speed, float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::DragFloat2(label, v, v_speed, v_min, v_max, format, flags);
}
bool IM::DragFloat3(const char* label, float v[3], float v_speed, float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::DragFloat3(label, v, v_speed, v_min, v_max, format, flags);
}
bool IM::DragFloat4(const char* label, float v[4], float v_speed, float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::DragFloat4(label, v, v_speed, v_min, v_max, format, flags);
}
bool IM::DragFloatRange2(const char* label, float* v_current_min, float* v_current_max, float v_speed, float v_min, float v_max, const char* format, const char* format_max, ImGuiSliderFlags flags)
{
    return ImGui::DragFloatRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, flags);
}
bool IM::DragInt(const char* label, int* v, float v_speed, int v_min, int v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::DragInt(label, v, v_speed, v_min, v_max, format, flags);
}
bool IM::DragInt2(const char* label, int v[2], float v_speed, int v_min, int v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::DragInt2(label, v, v_speed, v_min, v_max, format, flags);
}
bool IM::DragInt3(const char* label, int v[3], float v_speed, int v_min, int v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::DragInt3(label, v, v_speed, v_min, v_max, format, flags);
}
bool IM::DragInt4(const char* label, int v[4], float v_speed, int v_min, int v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::DragInt4(label, v, v_speed, v_min, v_max, format, flags);
}
bool IM::DragIntRange2(const char* label, int* v_current_min, int* v_current_max, float v_speed, int v_min, int v_max, const char* format, const char* format_max, ImGuiSliderFlags flags)
{
    return ImGui::DragIntRange2(label, v_current_min, v_current_max, v_speed, v_min, v_max, format, format_max, flags);
}
bool IM::DragScalar(const char* label, ImGuiDataType data_type, void* p_data, float v_speed, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::DragScalar(label, data_type, p_data, v_speed, p_min, p_max, format, flags);
}
bool IM::DragScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, float v_speed, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::DragScalarN(label, data_type, p_data, components, v_speed, p_min, p_max, format, flags);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Slider ///
//////////////////////////////////////////////////
bool IM::SliderFloat(const char* label, float* v, float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderFloat(label, v, v_min, v_max, format, flags);
}
bool IM::SliderFloat2(const char* label, float v[2], float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderFloat2(label, v, v_min, v_max, format, flags);
}
bool IM::SliderFloat3(const char* label, float v[3], float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderFloat3(label, v, v_min, v_max, format, flags);
}
bool IM::SliderFloat4(const char* label, float v[4], float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderFloat4(label, v, v_min, v_max, format, flags);
}
bool IM::SliderAngle(const char* label, float* v_rad, float v_degrees_min, float v_degrees_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderAngle(label, v_rad, v_degrees_min, v_degrees_max, format, flags);
}
bool IM::SliderInt(const char* label, int* v, int v_min, int v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderInt(label, v, v_min, v_max, format, flags);
}
bool IM::SliderInt2(const char* label, int v[2], int v_min, int v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderInt2(label, v, v_min, v_max, format, flags);
}
bool IM::SliderInt3(const char* label, int v[3], int v_min, int v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderInt3(label, v, v_min, v_max, format, flags);
}
bool IM::SliderInt4(const char* label, int v[4], int v_min, int v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderInt4(label, v, v_min, v_max, format, flags);
}
bool IM::SliderScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderScalar(label, data_type, p_data, p_min, p_max, format, flags);
}
bool IM::SliderScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::SliderScalarN(label, data_type, p_data, components, p_min, p_max, format, flags);
}
bool IM::VSliderFloat(const char* label, const ImVec2& size, float* v, float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::VSliderFloat(label, size, v, v_min, v_max, format, flags);
}
bool IM::VSliderInt(const char* label, const ImVec2& size, int* v, int v_min, int v_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::VSliderInt(label, size, v, v_min, v_max, format, flags);
}
bool IM::VSliderScalar(const char* label, const ImVec2& size, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags)
{
    return ImGui::VSliderScalar(label, size, data_type, p_data, p_min, p_max, format, flags);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Input ////
//////////////////////////////////////////////////
bool IM::InputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data)
{
    return ImGui::InputText(label, buf, buf_size, flags, callback, user_data);
}
bool IM::InputTextMultiline(const char* label, char* buf, size_t buf_size, const ImVec2& size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data)
{
    return ImGui::InputTextMultiline(label, buf, buf_size, size, flags, callback, user_data);
}
bool IM::InputTextWithHint(const char* label, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags, ImGuiInputTextCallback callback, void* user_data)
{
    return ImGui::InputTextWithHint(label, hint, buf, buf_size, flags, callback, user_data);
}
bool IM::InputFloat(const char* label, float* v, float step, float step_fast, const char* format, ImGuiInputTextFlags flags)
{
    return ImGui::InputFloat(label, v, step, step_fast, format, flags);
}
bool IM::InputFloat2(const char* label, float v[2], const char* format, ImGuiInputTextFlags flags)
{
    return ImGui::InputFloat2(label, v, format, flags);
}
bool IM::InputFloat3(const char* label, float v[3], const char* format, ImGuiInputTextFlags flags)
{
    return ImGui::InputFloat3(label, v, format, flags);
}
bool IM::InputFloat4(const char* label, float v[4], const char* format, ImGuiInputTextFlags flags)
{
    return ImGui::InputFloat4(label, v, format, flags);
}
bool IM::InputInt(const char* label, int* v, int step, int step_fast, ImGuiInputTextFlags flags)
{
    return ImGui::InputInt(label, v, step, step_fast, flags);
}
bool IM::InputInt2(const char* label, int v[2], ImGuiInputTextFlags flags)
{
    return ImGui::InputInt2(label, v, flags);
}
bool IM::InputInt3(const char* label, int v[3], ImGuiInputTextFlags flags)
{
    return ImGui::InputInt3(label, v, flags);
}
bool IM::InputInt4(const char* label, int v[4], ImGuiInputTextFlags flags)
{
    return ImGui::InputInt4(label, v, flags);
}
bool IM::InputDouble(const char* label, double* v, double step, double step_fast, const char* format, ImGuiInputTextFlags flags)
{
    return ImGui::InputDouble(label, v, step, step_fast, format, flags);
}
bool IM::InputScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_step, const void* p_step_fast, const char* format, ImGuiInputTextFlags flags)
{
    return ImGui::InputScalar(label, data_type, p_data, p_step, p_step_fast, format, flags);
}
bool IM::InputScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_step, const void* p_step_fast, const char* format, ImGuiInputTextFlags flags)
{
    return ImGui::InputScalarN(label, data_type, p_data, components, p_step, p_step_fast, format, flags);
}

/////////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Clr Picker //
/////////////////////////////////////////////////////
bool IM::ColorEdit3(const char* label, float col[3], ImGuiColorEditFlags flags)
{
    return ImGui::ColorEdit3(label, col, flags);
}
bool IM::ColorEdit4(const char* label, float col[4], ImGuiColorEditFlags flags)
{
    return ImGui::ColorEdit4(label, col, flags);
}
bool IM::ColorPicker3(const char* label, float col[3], ImGuiColorEditFlags flags)
{
    return ImGui::ColorPicker3(label, col, flags);
}
bool IM::ColorPicker4(const char* label, float col[4], ImGuiColorEditFlags flags, const float* ref_col)
{
    return ImGui::ColorPicker4(label, col, flags);
}
bool IM::ColorButton(const char* desc_id, const ImVec4& col, ImGuiColorEditFlags flags, ImVec2 size)
{
    return ImGui::ColorButton(desc_id, col, flags, size);
}
void IM::SetColorEditOptions(ImGuiColorEditFlags flags)
{
    ImGui::SetColorEditOptions(flags);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Tree /////
//////////////////////////////////////////////////
bool IM::TreeNode(const char* label)
{
    return ImGui::TreeNode(label);
}
bool IM::TreeNode(const char* str_id, const char* fmt, ...)
{
    static bool ret;
    va_list args;        
    va_start(args, fmt);
    ret = ImGui::TreeNodeV(str_id, fmt, args);
    va_end(args);
    return ret;
}
bool IM::TreeNode(const void* ptr_id, const char* fmt, ...)
{
    static bool ret;
    va_list args;        
    va_start(args, fmt);
    ret = ImGui::TreeNodeV(ptr_id, fmt, args);
    va_end(args);
    return ret;
}
bool IM::TreeNodeV(const char* str_id, const char* fmt, va_list args)
{
    return ImGui::TreeNodeV(str_id, fmt, args);
}
bool IM::TreeNodeV(const void* ptr_id, const char* fmt, va_list args)
{
    return ImGui::TreeNodeV(ptr_id, fmt, args);
}
bool IM::TreeNodeEx(const char* label, ImGuiTreeNodeFlags flags)
{
    return ImGui::TreeNodeEx(label, flags);
}
bool IM::TreeNodeEx(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, ...)
{
    static bool ret;
    va_list args;
    va_start(args, fmt);
    ret = ImGui::TreeNodeExV(str_id, flags, fmt, args);
    va_end(args);
    return ret;
}
bool IM::TreeNodeEx(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, ...)
{
    static bool ret;
    va_list args;
    va_start(args, fmt);
    ret = ImGui::TreeNodeExV(ptr_id, flags, fmt, args);
    va_end(args);
    return ret;
}
bool IM::TreeNodeExV(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, va_list args)
{
    return ImGui::TreeNodeExV(str_id, flags, fmt, args);
}
bool IM::TreeNodeExV(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, va_list args)
{
    return ImGui::TreeNodeExV(ptr_id, flags, fmt, args);
}
void IM::TreePush(const char* str_id)
{
    ImGui::TreePush(str_id);
}
void IM::TreePush(const void* ptr_id)
{
    ImGui::TreePush(ptr_id);
}
void IM::TreePop()
{
    ImGui::TreePop();
}
float IM::GetTreeNodeToLabelSpacing()
{
    return ImGui::GetTreeNodeToLabelSpacing();
}
bool IM::CollapsingHeader(const char* label, ImGuiTreeNodeFlags flags)
{
    return ImGui::CollapsingHeader(label, flags);
}
bool IM::CollapsingHeader(const char* label, bool* p_visible, ImGuiTreeNodeFlags flags)
{
    return ImGui::CollapsingHeader(label, p_visible, flags);
}
void IM::SetNextItemOpen(bool is_open, ImGuiCond cond)
{
    ImGui::SetNextItemOpen(is_open, cond);
}

///////////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Selectables ///
///////////////////////////////////////////////////////
bool IM::Selectable(const char* label, bool selected, ImGuiSelectableFlags flags, const ImVec2& size)
{
    return ImGui::Selectable(label, selected, flags, size);
}
bool IM::Selectable(const char* label, bool* p_selected, ImGuiSelectableFlags flags, const ImVec2& size)
{
    return ImGui::Selectable(label, p_selected, flags, size);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: ListBox //
//////////////////////////////////////////////////
bool IM::BeginListBox(const char* label, const ImVec2& size)
{
    return ImGui::BeginListBox(label, size);
}
void IM::EndListBox()
{
    ImGui::EndListBox();
}
bool IM::ListBox(const char* label, int* current_item, const char* const items[], int items_count, int height_in_items)
{
    return ImGui::ListBox(label, current_item, items, items_count, height_in_items);
}
bool IM::ListBox(const char* label, int* current_item, bool (*items_getter)(void*, int, const char**), void* data, int items_count, int height_in_items)
{
    return ImGui::ListBox(label, current_item, items_getter, data, items_count, height_in_items);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Plots ////
//////////////////////////////////////////////////
void IM::PlotLines(const char* label, const float* values, int values_count, int values_offset, const char* overlay_text, float scale_min, float scale_max, ImVec2 graph_size, int stride)
{
    ImGui::PlotLines(label, values, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size, stride);
}
void IM::PlotLines(const char* label, float(*values_getter)(void* data, int idx), void* data, int values_count, int values_offset, const char* overlay_text, float scale_min, float scale_max, ImVec2 graph_size)
{
    ImGui::PlotLines(label, values_getter, data, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size);
}
void IM::PlotHistogram(const char* label, const float* values, int values_count, int values_offset, const char* overlay_text, float scale_min, float scale_max, ImVec2 graph_size, int stride)
{
    ImGui::PlotHistogram(label, values, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size, stride);
}
void IM::PlotHistogram(const char* label, float(*values_getter)(void* data, int idx), void* data, int values_count, int values_offset, const char* overlay_text, float scale_min, float scale_max, ImVec2 graph_size)
{
    ImGui::PlotHistogram(label, values_getter, data, values_count, values_offset, overlay_text, scale_min, scale_max, graph_size);
}

//////////////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Value helper /////
//////////////////////////////////////////////////////////
void IM::Value(const char* prefix, bool b)
{
    ImGui::Value(prefix, b);
}
void IM::Value(const char* prefix, int v)
{
    ImGui::Value(prefix, v);
}
void IM::Value(const char* prefix, unsigned int v)
{
    ImGui::Value(prefix, v);
}
void IM::Value(const char* prefix, float v, const char* float_format)
{
    ImGui::Value(prefix, v, float_format);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Menus ////
//////////////////////////////////////////////////
bool IM::BeginMenuBar()
{
    return ImGui::BeginMenuBar();
}
void IM::EndMenuBar()
{
    ImGui::EndMenuBar();
}
bool IM::BeginMainMenuBar()
{
    return ImGui::BeginMainMenuBar();
}
void IM::EndMainMenuBar()
{
    ImGui::EndMainMenuBar();
}
bool IM::BeginMenu(const char* label, bool enabled)
{
    return ImGui::BeginMenu(label, enabled);
}
void IM::EndMenu()
{
    ImGui::EndMenu();
}
bool IM::MenuItem(const char* label, const char* shortcut, bool selected, bool enabled)
{
    return ImGui::MenuItem(label, shortcut, selected, enabled);
}
bool IM::MenuItem(const char* label, const char* shortcut, bool* p_selected, bool enabled)
{
    return ImGui::MenuItem(label, shortcut, p_selected, enabled);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Tooltip //
//////////////////////////////////////////////////
void IM::BeginTooltip()
{
    ImGui::BeginTooltip();
}
void IM::EndTooltip()
{
    ImGui::EndTooltip();
}
void IM::SetTooltip(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    ImGui::SetTooltipV(fmt, args);
    va_end(args);
}
void IM::SetTooltipV(const char* fmt, va_list args)
{
    ImGui::SetTooltipV(fmt, args);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Popup ////
//////////////////////////////////////////////////
bool IM::BeginPopup(const char* str_id, ImGuiWindowFlags flags)
{
    return ImGui::BeginPopup(str_id, flags);
}
bool IM::BeginPopupModal(const char* name, bool* p_open, ImGuiWindowFlags flags)
{
    return ImGui::BeginPopupModal(name, p_open, flags);
}
void IM::EndPopup()
{
    ImGui::EndPopup();
}
void IM::OpenPopup(const char* str_id, ImGuiPopupFlags popup_flags)
{
    ImGui::OpenPopup(str_id, popup_flags);
}
void IM::OpenPopup(ImGuiID id, ImGuiPopupFlags popup_flags)
{
    ImGui::OpenPopup(id, popup_flags);
}
void IM::OpenPopupOnItemClick(const char* str_id, ImGuiPopupFlags popup_flags)
{
    ImGui::OpenPopupOnItemClick(str_id, popup_flags);
}
void IM::CloseCurrentPopup()
{
    ImGui::CloseCurrentPopup();
}        
bool IM::BeginPopupContextItem(const char* str_id, ImGuiPopupFlags popup_flags)
{
    return ImGui::BeginPopupContextItem(str_id, popup_flags);
}
bool IM::BeginPopupContextWindow(const char* str_id, ImGuiPopupFlags popup_flags)
{
    return ImGui::BeginPopupContextWindow(str_id, popup_flags);
}
bool IM::BeginPopupContextVoid(const char* str_id, ImGuiPopupFlags popup_flags)
{
    return ImGui::BeginPopupContextVoid(str_id, popup_flags);
}
bool IM::IsPopupOpen(const char* str_id, ImGuiPopupFlags flags)
{
    return ImGui::IsPopupOpen(str_id, flags);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Table ////
//////////////////////////////////////////////////
bool IM::BeginTable(const char* str_id, int column, ImGuiTableFlags flags, const ImVec2& outer_size, float inner_width)
{
    return ImGui::BeginTable(str_id, column, flags, outer_size, inner_width);
}
void IM::EndTable()
{
    ImGui::EndTable();
}
void IM::TableNextRow(ImGuiTableRowFlags row_flags, float min_row_height)
{
    ImGui::TableNextRow(row_flags, min_row_height);
}
bool IM::TableNextColumn()
{
    return ImGui::TableNextColumn();
}
bool IM::TableSetColumnIndex(int column_n)
{
    return ImGui::TableSetColumnIndex(column_n);
}
void IM::TableSetupColumn(const char* label, ImGuiTableColumnFlags flags, float init_width_or_weight, ImGuiID user_id)
{
    ImGui::TableSetupColumn(label, flags, init_width_or_weight, user_id);
}
void IM::TableSetupScrollFreeze(int cols, int rows)
{
    ImGui::TableSetupScrollFreeze(cols, rows);
}
void IM::TableHeadersRow()
{
    ImGui::TableHeadersRow();
}
void IM::TableHeader(const char* label)
{
    ImGui::TableHeader(label);
}
ImGuiTableSortSpecs* IM::TableGetSortSpecs()
{
    return ImGui::TableGetSortSpecs();
}
int IM::TableGetColumnCount()
{
    return ImGui::TableGetColumnCount();
}
int IM::TableGetColumnIndex()
{
    return ImGui::TableGetColumnIndex();
}
int IM::TableGetRowIndex()
{
    return ImGui::TableGetRowIndex();
}
const char* IM::TableGetColumnName(int column_n)
{
    return ImGui::TableGetColumnName(column_n);
}
ImGuiTableColumnFlags IM::TableGetColumnFlags(int column_n)
{
    return ImGui::TableGetColumnFlags(column_n);
}
void IM::TableSetColumnEnabled(int column_n, bool v)
{
    ImGui::TableSetColumnEnabled(column_n, v);
}
void IM::TableSetBgColor(ImGuiTableBgTarget target, ImU32 color, int column_n)
{
    ImGui::TableSetBgColor(target, color, column_n);
}
void IM::Columns(int count, const char* id, bool border)
{
    ImGui::Columns(count, id, border);
}
void IM::NextColumn()
{
    ImGui::NextColumn();
}
int IM::GetColumnIndex()
{
    return ImGui::GetColumnIndex();
}
float IM::GetColumnWidth(int column_index)
{
    return ImGui::GetColumnWidth(column_index);
}
void IM::SetColumnWidth(int column_index, float width)
{
    ImGui::SetColumnWidth(column_index, width);
}
float IM::GetColumnOffset(int column_index)
{
    return ImGui::GetColumnOffset(column_index);
}
void IM::SetColumnOffset(int column_index, float offset_x)
{
    ImGui::SetColumnOffset(column_index, offset_x);
}
int IM::GetColumnsCount()
{
    return ImGui::GetColumnsCount();
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Tabs /////
//////////////////////////////////////////////////
bool IM::BeginTabBar(const char* str_id, ImGuiTabBarFlags flags)
{
    return ImGui::BeginTabBar(str_id, flags);
}
void IM::EndTabBar()
{
    ImGui::EndTabBar();
}
bool IM::BeginTabItem(const char* label, bool* p_open, ImGuiTabItemFlags flags)
{
    return ImGui::BeginTabItem(label, p_open, flags);
}
void IM::EndTabItem()
{
    ImGui::EndTabItem();
}
bool IM::TabItemButton(const char* label, ImGuiTabItemFlags flags)
{
    return ImGui::TabItemButton(label, flags);
}
void IM::SetTabItemClosed(const char* tab_or_docked_window_label)
{
    ImGui::SetTabItemClosed(tab_or_docked_window_label);
}

//////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Focus ////
//////////////////////////////////////////////////
void IM::SetItemDefaultFocus()
{
    ImGui::SetItemDefaultFocus();
}
void IM::SetKeyboardFocusHere(int offset)
{
    ImGui::SetKeyboardFocusHere(offset);
}

/////////////////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Widget/item utils ///
/////////////////////////////////////////////////////////////
bool IM::IsItemHovered(ImGuiHoveredFlags flags)
{
    return ImGui::IsItemHovered(flags);
}
bool IM::IsItemActive()
{
    return ImGui::IsItemActive();
}
bool IM::IsItemFocused()
{
    return ImGui::IsItemFocused();
}
bool IM::IsItemClicked(ImGuiMouseButton mouse_button)
{
    return ImGui::IsItemClicked(mouse_button);
}
bool IM::IsItemVisible()
{
    return ImGui::IsItemVisible();
}
bool IM::IsItemEdited()
{
    return ImGui::IsItemEdited();
}
bool IM::IsItemActivated()
{
    return ImGui::IsItemActivated();
}
bool IM::IsItemDeactivated()
{
    return ImGui::IsItemDeactivated();
}
bool IM::IsItemDeactivatedAfterEdit()
{
    return ImGui::IsItemDeactivatedAfterEdit();
}
bool IM::IsItemToggledOpen()
{
    return ImGui::IsItemToggledOpen();
}
bool IM::IsAnyItemHovered()
{
    return ImGui::IsAnyItemHovered();
}
bool IM::IsAnyItemActive()
{
    return ImGui::IsAnyItemActive();
}
bool IM::IsAnyItemFocused()
{
    return ImGui::IsAnyItemFocused();
}
ImVec2 IM::GetItemRectMin()
{
    return ImGui::GetItemRectMin();
}
ImVec2 IM::GetItemRectMax()
{
    return ImGui::GetItemRectMax();
}
ImVec2 IM::GetItemRectSize()
{
    return ImGui::GetItemRectSize();
}
void IM::SetItemAllowOverlap()
{
    ImGui::SetItemAllowOverlap();
}

///////////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Misc utils ////
///////////////////////////////////////////////////////
bool IM::IsRectVisible(const ImVec2& size)
{
    return ImGui::IsRectVisible(size);
}
bool IM::IsRectVisible(const ImVec2& rect_min, const ImVec2& rect_max)
{
    return ImGui::IsRectVisible(rect_min, rect_max);
}
double IM::GetTime()
{
    return ImGui::GetTime();
}
int IM::GetFrameCount()
{
    return ImGui::GetFrameCount();
}
const char* IM::GetStyleColorName(ImGuiCol idx)
{
    return ImGui::GetStyleColorName(idx);
}
bool IM::BeginChildFrame(ImGuiID id, const ImVec2& size, ImGuiWindowFlags flags)
{
    return ImGui::BeginChildFrame(id, size, flags);
}
void IM::EndChildFrame()
{
    ImGui::EndChildFrame();
}
ImVec2 IM::CalcTextSize(const char* text, const char* text_end, bool hide_text_after_double_hash, float wrap_width)
{
    return ImGui::CalcTextSize(text, text_end, hide_text_after_double_hash, wrap_width);
}
ImVec4 IM::ColorConvertU32ToFloat4(ImU32 in)
{
    return ImGui::ColorConvertU32ToFloat4(in);
}
ImU32 IM::ColorConvertFloat4ToU32(const ImVec4& in)
{
    return ImGui::ColorConvertFloat4ToU32(in);
}
void IM::ColorConvertRGBtoHSV(float r, float g, float b, float& out_h, float& out_s, float& out_v)
{
    ImGui::ColorConvertRGBtoHSV(r, g, b, out_h, out_s, out_v);
}
void IM::ColorConvertHSVtoRGB(float h, float s, float v, float& out_r, float& out_g, float& out_b)
{
    ImGui::ColorConvertHSVtoRGB(h, s, v, out_r, out_g, out_b);
}

///////////////////////////////////////////////////////
/////////////////////////// IMGUI PART: Mouse utils ///
///////////////////////////////////////////////////////
bool IM::IsMouseDown(ImGuiMouseButton button)
{
    return ImGui::IsMouseDown(button);
}
bool IM::IsMouseClicked(ImGuiMouseButton button, bool repeat)
{
    return ImGui::IsMouseClicked(button, repeat);
}
bool IM::IsMouseReleased(ImGuiMouseButton button)
{
    return ImGui::IsMouseReleased(button);
}
bool IM::IsMouseDoubleClicked(ImGuiMouseButton button)
{
    return ImGui::IsMouseDoubleClicked(button);
}
int IM::GetMouseClickedCount(ImGuiMouseButton button)
{
    return ImGui::GetMouseClickedCount(button);
}
bool IM::IsMouseHoveringRect(const ImVec2& r_min, const ImVec2& r_max, bool clip)
{
    return ImGui::IsMouseHoveringRect(r_min, r_max, clip);
}
bool IM::IsMousePosValid(const ImVec2* mouse_pos)
{
    return ImGui::IsMousePosValid(mouse_pos);
}
bool IM::IsAnyMouseDown()
{
    return ImGui::IsAnyMouseDown();
}
ImVec2 IM::GetMousePos()
{
    return ImGui::GetMousePos();
}
ImVec2 IM::GetMousePosOnOpeningCurrentPopup()
{
    return ImGui::GetMousePosOnOpeningCurrentPopup();
}
bool IM::IsMouseDragging(ImGuiMouseButton button, float lock_threshold)
{
    return ImGui::IsMouseDragging(button, lock_threshold);
}
ImVec2 IM::GetMouseDragDelta(ImGuiMouseButton button, float lock_threshold)
{
    return ImGui::GetMouseDragDelta(button, lock_threshold);
}