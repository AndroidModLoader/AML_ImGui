#pragma once // IMGUI_AML_INTERFACE

#include <stdarg.h>

////////////////////////////////////////////////////////////
// Scroll to the bottom if you need interface's functions //
////////////////////////////////////////////////////////////

// "type" variable of OnTouchEvent
#define TOUCH_RELEASE   1
#define TOUCH_PUSH      2
#define TOUCH_MOVE      3

#if !defined(IGNORE_IMGUI_THINGS)
// Types
#ifndef ImTextureID
    typedef void* ImTextureID;
#endif
struct ImFont;
typedef int ImGuiCol; typedef int ImGuiCond; typedef int ImGuiDataType; typedef int ImGuiDir;
typedef int ImGuiKey; typedef int ImGuiNavInput; typedef int ImGuiMouseButton; typedef int ImGuiMouseCursor;
typedef int ImGuiSortDirection; typedef int ImGuiStyleVar; typedef int ImGuiTableBgTarget; typedef int ImDrawFlags;
typedef int ImDrawListFlags; typedef int ImFontAtlasFlags; typedef int ImGuiBackendFlags; typedef int ImGuiButtonFlags;
typedef int ImGuiColorEditFlags; typedef int ImGuiConfigFlags; typedef int ImGuiComboFlags; typedef int ImGuiDragDropFlags;
typedef int ImGuiFocusedFlags; typedef int ImGuiHoveredFlags; typedef int ImGuiInputTextFlags; typedef int ImGuiKeyModFlags;
typedef int ImGuiPopupFlags; typedef int ImGuiSelectableFlags; typedef int ImGuiSliderFlags; typedef int ImGuiTabBarFlags;
typedef int ImGuiTabItemFlags; typedef int ImGuiTableFlags; typedef int ImGuiTableColumnFlags; typedef int ImGuiTableRowFlags;
typedef int ImGuiTreeNodeFlags; typedef int ImGuiViewportFlags; typedef int ImGuiWindowFlags;
// Flags for ImGui::Begin()
enum ImGuiWindowFlags_
{
    ImGuiWindowFlags_None                   = 0,
    ImGuiWindowFlags_NoTitleBar             = 1 << 0,   // Disable title-bar
    ImGuiWindowFlags_NoResize               = 1 << 1,   // Disable user resizing with the lower-right grip
    ImGuiWindowFlags_NoMove                 = 1 << 2,   // Disable user moving the window
    ImGuiWindowFlags_NoScrollbar            = 1 << 3,   // Disable scrollbars (window can still scroll with mouse or programmatically)
    ImGuiWindowFlags_NoScrollWithMouse      = 1 << 4,   // Disable user vertically scrolling with mouse wheel. On child window, mouse wheel will be forwarded to the parent unless NoScrollbar is also set.
    ImGuiWindowFlags_NoCollapse             = 1 << 5,   // Disable user collapsing window by double-clicking on it. Also referred to as Window Menu Button (e.g. within a docking node).
    ImGuiWindowFlags_AlwaysAutoResize       = 1 << 6,   // Resize every window to its content every frame
    ImGuiWindowFlags_NoBackground           = 1 << 7,   // Disable drawing background color (WindowBg, etc.) and outside border. Similar as using SetNextWindowBgAlpha(0.0f).
    ImGuiWindowFlags_NoSavedSettings        = 1 << 8,   // Never load/save settings in .ini file
    ImGuiWindowFlags_NoMouseInputs          = 1 << 9,   // Disable catching mouse, hovering test with pass through.
    ImGuiWindowFlags_MenuBar                = 1 << 10,  // Has a menu-bar
    ImGuiWindowFlags_HorizontalScrollbar    = 1 << 11,  // Allow horizontal scrollbar to appear (off by default). You may use SetNextWindowContentSize(ImVec2(width,0.0f)); prior to calling Begin() to specify width. Read code in imgui_demo in the "Horizontal Scrolling" section.
    ImGuiWindowFlags_NoFocusOnAppearing     = 1 << 12,  // Disable taking focus when transitioning from hidden to visible state
    ImGuiWindowFlags_NoBringToFrontOnFocus  = 1 << 13,  // Disable bringing window to front when taking focus (e.g. clicking on it or programmatically giving it focus)
    ImGuiWindowFlags_AlwaysVerticalScrollbar= 1 << 14,  // Always show vertical scrollbar (even if ContentSize.y < Size.y)
    ImGuiWindowFlags_AlwaysHorizontalScrollbar=1<< 15,  // Always show horizontal scrollbar (even if ContentSize.x < Size.x)
    ImGuiWindowFlags_AlwaysUseWindowPadding = 1 << 16,  // Ensure child windows without border uses style.WindowPadding (ignored by default for non-bordered child windows, because more convenient)
    ImGuiWindowFlags_NoNavInputs            = 1 << 18,  // No gamepad/keyboard navigation within the window
    ImGuiWindowFlags_NoNavFocus             = 1 << 19,  // No focusing toward this window with gamepad/keyboard navigation (e.g. skipped by CTRL+TAB)
    ImGuiWindowFlags_UnsavedDocument        = 1 << 20,  // Display a dot next to the title. When used in a tab/docking context, tab is selected when clicking the X + closure is not assumed (will wait for user to stop submitting the tab). Otherwise closure is assumed when pressing the X, so if you keep submitting the tab may reappear at end of tab bar.
    ImGuiWindowFlags_NoNav                  = ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus,
    ImGuiWindowFlags_NoDecoration           = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse,
    ImGuiWindowFlags_NoInputs               = ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus,

    // [Internal]
    ImGuiWindowFlags_NavFlattened           = 1 << 23,  // [BETA] On child window: allow gamepad/keyboard navigation to cross over parent border to this child or between sibling child windows.
    ImGuiWindowFlags_ChildWindow            = 1 << 24,  // Don't use! For internal use by BeginChild()
    ImGuiWindowFlags_Tooltip                = 1 << 25,  // Don't use! For internal use by BeginTooltip()
    ImGuiWindowFlags_Popup                  = 1 << 26,  // Don't use! For internal use by BeginPopup()
    ImGuiWindowFlags_Modal                  = 1 << 27,  // Don't use! For internal use by BeginPopupModal()
    ImGuiWindowFlags_ChildMenu              = 1 << 28   // Don't use! For internal use by BeginMenu()

    // [Obsolete]
    //ImGuiWindowFlags_ResizeFromAnySide    = 1 << 17,  // --> Set io.ConfigWindowsResizeFromEdges=true and make sure mouse cursors are supported by backend (io.BackendFlags & ImGuiBackendFlags_HasMouseCursors)
};

// Flags for ImGui::InputText()
enum ImGuiInputTextFlags_
{
    ImGuiInputTextFlags_None                = 0,
    ImGuiInputTextFlags_CharsDecimal        = 1 << 0,   // Allow 0123456789.+-*/
    ImGuiInputTextFlags_CharsHexadecimal    = 1 << 1,   // Allow 0123456789ABCDEFabcdef
    ImGuiInputTextFlags_CharsUppercase      = 1 << 2,   // Turn a..z into A..Z
    ImGuiInputTextFlags_CharsNoBlank        = 1 << 3,   // Filter out spaces, tabs
    ImGuiInputTextFlags_AutoSelectAll       = 1 << 4,   // Select entire text when first taking mouse focus
    ImGuiInputTextFlags_EnterReturnsTrue    = 1 << 5,   // Return 'true' when Enter is pressed (as opposed to every time the value was modified). Consider looking at the IsItemDeactivatedAfterEdit() function.
    ImGuiInputTextFlags_CallbackCompletion  = 1 << 6,   // Callback on pressing TAB (for completion handling)
    ImGuiInputTextFlags_CallbackHistory     = 1 << 7,   // Callback on pressing Up/Down arrows (for history handling)
    ImGuiInputTextFlags_CallbackAlways      = 1 << 8,   // Callback on each iteration. User code may query cursor position, modify text buffer.
    ImGuiInputTextFlags_CallbackCharFilter  = 1 << 9,   // Callback on character inputs to replace or discard them. Modify 'EventChar' to replace or discard, or return 1 in callback to discard.
    ImGuiInputTextFlags_AllowTabInput       = 1 << 10,  // Pressing TAB input a '\t' character into the text field
    ImGuiInputTextFlags_CtrlEnterForNewLine = 1 << 11,  // In multi-line mode, unfocus with Enter, add new line with Ctrl+Enter (default is opposite: unfocus with Ctrl+Enter, add line with Enter).
    ImGuiInputTextFlags_NoHorizontalScroll  = 1 << 12,  // Disable following the cursor horizontally
    ImGuiInputTextFlags_AlwaysOverwrite     = 1 << 13,  // Overwrite mode
    ImGuiInputTextFlags_ReadOnly            = 1 << 14,  // Read-only mode
    ImGuiInputTextFlags_Password            = 1 << 15,  // Password mode, display all characters as '*'
    ImGuiInputTextFlags_NoUndoRedo          = 1 << 16,  // Disable undo/redo. Note that input text owns the text data while active, if you want to provide your own undo/redo stack you need e.g. to call ClearActiveID().
    ImGuiInputTextFlags_CharsScientific     = 1 << 17,  // Allow 0123456789.+-*/eE (Scientific notation input)
    ImGuiInputTextFlags_CallbackResize      = 1 << 18,  // Callback on buffer capacity changes request (beyond 'buf_size' parameter value), allowing the string to grow. Notify when the string wants to be resized (for string types which hold a cache of their Size). You will be provided a new BufSize in the callback and NEED to honor it. (see misc/cpp/imgui_stdlib.h for an example of using this)
    ImGuiInputTextFlags_CallbackEdit        = 1 << 19   // Callback on any edit (note that InputText() already returns true on edit, the callback is useful mainly to manipulate the underlying buffer while focus is active)

    // Obsolete names (will be removed soon)
#ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
    , ImGuiInputTextFlags_AlwaysInsertMode    = ImGuiInputTextFlags_AlwaysOverwrite   // [renamed in 1.82] name was not matching behavior
#endif
};

// Flags for ImGui::TreeNodeEx(), ImGui::CollapsingHeader*()
enum ImGuiTreeNodeFlags_
{
    ImGuiTreeNodeFlags_None                 = 0,
    ImGuiTreeNodeFlags_Selected             = 1 << 0,   // Draw as selected
    ImGuiTreeNodeFlags_Framed               = 1 << 1,   // Draw frame with background (e.g. for CollapsingHeader)
    ImGuiTreeNodeFlags_AllowItemOverlap     = 1 << 2,   // Hit testing to allow subsequent widgets to overlap this one
    ImGuiTreeNodeFlags_NoTreePushOnOpen     = 1 << 3,   // Don't do a TreePush() when open (e.g. for CollapsingHeader) = no extra indent nor pushing on ID stack
    ImGuiTreeNodeFlags_NoAutoOpenOnLog      = 1 << 4,   // Don't automatically and temporarily open node when Logging is active (by default logging will automatically open tree nodes)
    ImGuiTreeNodeFlags_DefaultOpen          = 1 << 5,   // Default node to be open
    ImGuiTreeNodeFlags_OpenOnDoubleClick    = 1 << 6,   // Need double-click to open node
    ImGuiTreeNodeFlags_OpenOnArrow          = 1 << 7,   // Only open when clicking on the arrow part. If ImGuiTreeNodeFlags_OpenOnDoubleClick is also set, single-click arrow or double-click all box to open.
    ImGuiTreeNodeFlags_Leaf                 = 1 << 8,   // No collapsing, no arrow (use as a convenience for leaf nodes).
    ImGuiTreeNodeFlags_Bullet               = 1 << 9,   // Display a bullet instead of arrow
    ImGuiTreeNodeFlags_FramePadding         = 1 << 10,  // Use FramePadding (even for an unframed text node) to vertically align text baseline to regular widget height. Equivalent to calling AlignTextToFramePadding().
    ImGuiTreeNodeFlags_SpanAvailWidth       = 1 << 11,  // Extend hit box to the right-most edge, even if not framed. This is not the default in order to allow adding other items on the same line. In the future we may refactor the hit system to be front-to-back, allowing natural overlaps and then this can become the default.
    ImGuiTreeNodeFlags_SpanFullWidth        = 1 << 12,  // Extend hit box to the left-most and right-most edges (bypass the indented area).
    ImGuiTreeNodeFlags_NavLeftJumpsBackHere = 1 << 13,  // (WIP) Nav: left direction may move to this TreeNode() from any of its child (items submitted between TreeNode and TreePop)
    //ImGuiTreeNodeFlags_NoScrollOnOpen     = 1 << 14,  // FIXME: TODO: Disable automatic scroll on TreePop() if node got just open and contents is not visible
    ImGuiTreeNodeFlags_CollapsingHeader     = ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_NoAutoOpenOnLog
};

// Flags for OpenPopup*(), BeginPopupContext*(), IsPopupOpen() functions.
// - To be backward compatible with older API which took an 'int mouse_button = 1' argument, we need to treat
//   small flags values as a mouse button index, so we encode the mouse button in the first few bits of the flags.
//   It is therefore guaranteed to be legal to pass a mouse button index in ImGuiPopupFlags.
// - For the same reason, we exceptionally default the ImGuiPopupFlags argument of BeginPopupContextXXX functions to 1 instead of 0.
//   IMPORTANT: because the default parameter is 1 (==ImGuiPopupFlags_MouseButtonRight), if you rely on the default parameter
//   and want to another another flag, you need to pass in the ImGuiPopupFlags_MouseButtonRight flag.
// - Multiple buttons currently cannot be combined/or-ed in those functions (we could allow it later).
enum ImGuiPopupFlags_
{
    ImGuiPopupFlags_None                    = 0,
    ImGuiPopupFlags_MouseButtonLeft         = 0,        // For BeginPopupContext*(): open on Left Mouse release. Guaranteed to always be == 0 (same as ImGuiMouseButton_Left)
    ImGuiPopupFlags_MouseButtonRight        = 1,        // For BeginPopupContext*(): open on Right Mouse release. Guaranteed to always be == 1 (same as ImGuiMouseButton_Right)
    ImGuiPopupFlags_MouseButtonMiddle       = 2,        // For BeginPopupContext*(): open on Middle Mouse release. Guaranteed to always be == 2 (same as ImGuiMouseButton_Middle)
    ImGuiPopupFlags_MouseButtonMask_        = 0x1F,
    ImGuiPopupFlags_MouseButtonDefault_     = 1,
    ImGuiPopupFlags_NoOpenOverExistingPopup = 1 << 5,   // For OpenPopup*(), BeginPopupContext*(): don't open if there's already a popup at the same level of the popup stack
    ImGuiPopupFlags_NoOpenOverItems         = 1 << 6,   // For BeginPopupContextWindow(): don't return true when hovering items, only when hovering empty space
    ImGuiPopupFlags_AnyPopupId              = 1 << 7,   // For IsPopupOpen(): ignore the ImGuiID parameter and test for any popup.
    ImGuiPopupFlags_AnyPopupLevel           = 1 << 8,   // For IsPopupOpen(): search/test at any level of the popup stack (default test in the current level)
    ImGuiPopupFlags_AnyPopup                = ImGuiPopupFlags_AnyPopupId | ImGuiPopupFlags_AnyPopupLevel
};

// Flags for ImGui::Selectable()
enum ImGuiSelectableFlags_
{
    ImGuiSelectableFlags_None               = 0,
    ImGuiSelectableFlags_DontClosePopups    = 1 << 0,   // Clicking this don't close parent popup window
    ImGuiSelectableFlags_SpanAllColumns     = 1 << 1,   // Selectable frame can span all columns (text will still fit in current column)
    ImGuiSelectableFlags_AllowDoubleClick   = 1 << 2,   // Generate press events on double clicks too
    ImGuiSelectableFlags_Disabled           = 1 << 3,   // Cannot be selected, display grayed out text
    ImGuiSelectableFlags_AllowItemOverlap   = 1 << 4    // (WIP) Hit testing to allow subsequent widgets to overlap this one
};

// Flags for ImGui::BeginCombo()
enum ImGuiComboFlags_
{
    ImGuiComboFlags_None                    = 0,
    ImGuiComboFlags_PopupAlignLeft          = 1 << 0,   // Align the popup toward the left by default
    ImGuiComboFlags_HeightSmall             = 1 << 1,   // Max ~4 items visible. Tip: If you want your combo popup to be a specific size you can use SetNextWindowSizeConstraints() prior to calling BeginCombo()
    ImGuiComboFlags_HeightRegular           = 1 << 2,   // Max ~8 items visible (default)
    ImGuiComboFlags_HeightLarge             = 1 << 3,   // Max ~20 items visible
    ImGuiComboFlags_HeightLargest           = 1 << 4,   // As many fitting items as possible
    ImGuiComboFlags_NoArrowButton           = 1 << 5,   // Display on the preview box without the square arrow button
    ImGuiComboFlags_NoPreview               = 1 << 6,   // Display only a square arrow button
    ImGuiComboFlags_HeightMask_             = ImGuiComboFlags_HeightSmall | ImGuiComboFlags_HeightRegular | ImGuiComboFlags_HeightLarge | ImGuiComboFlags_HeightLargest
};

// Flags for ImGui::BeginTabBar()
enum ImGuiTabBarFlags_
{
    ImGuiTabBarFlags_None                           = 0,
    ImGuiTabBarFlags_Reorderable                    = 1 << 0,   // Allow manually dragging tabs to re-order them + New tabs are appended at the end of list
    ImGuiTabBarFlags_AutoSelectNewTabs              = 1 << 1,   // Automatically select new tabs when they appear
    ImGuiTabBarFlags_TabListPopupButton             = 1 << 2,   // Disable buttons to open the tab list popup
    ImGuiTabBarFlags_NoCloseWithMiddleMouseButton   = 1 << 3,   // Disable behavior of closing tabs (that are submitted with p_open != NULL) with middle mouse button. You can still repro this behavior on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open = false.
    ImGuiTabBarFlags_NoTabListScrollingButtons      = 1 << 4,   // Disable scrolling buttons (apply when fitting policy is ImGuiTabBarFlags_FittingPolicyScroll)
    ImGuiTabBarFlags_NoTooltip                      = 1 << 5,   // Disable tooltips when hovering a tab
    ImGuiTabBarFlags_FittingPolicyResizeDown        = 1 << 6,   // Resize tabs when they don't fit
    ImGuiTabBarFlags_FittingPolicyScroll            = 1 << 7,   // Add scroll buttons when tabs don't fit
    ImGuiTabBarFlags_FittingPolicyMask_             = ImGuiTabBarFlags_FittingPolicyResizeDown | ImGuiTabBarFlags_FittingPolicyScroll,
    ImGuiTabBarFlags_FittingPolicyDefault_          = ImGuiTabBarFlags_FittingPolicyResizeDown
};

// Flags for ImGui::BeginTabItem()
enum ImGuiTabItemFlags_
{
    ImGuiTabItemFlags_None                          = 0,
    ImGuiTabItemFlags_UnsavedDocument               = 1 << 0,   // Display a dot next to the title + tab is selected when clicking the X + closure is not assumed (will wait for user to stop submitting the tab). Otherwise closure is assumed when pressing the X, so if you keep submitting the tab may reappear at end of tab bar.
    ImGuiTabItemFlags_SetSelected                   = 1 << 1,   // Trigger flag to programmatically make the tab selected when calling BeginTabItem()
    ImGuiTabItemFlags_NoCloseWithMiddleMouseButton  = 1 << 2,   // Disable behavior of closing tabs (that are submitted with p_open != NULL) with middle mouse button. You can still repro this behavior on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open = false.
    ImGuiTabItemFlags_NoPushId                      = 1 << 3,   // Don't call PushID(tab->ID)/PopID() on BeginTabItem()/EndTabItem()
    ImGuiTabItemFlags_NoTooltip                     = 1 << 4,   // Disable tooltip for the given tab
    ImGuiTabItemFlags_NoReorder                     = 1 << 5,   // Disable reordering this tab or having another tab cross over this tab
    ImGuiTabItemFlags_Leading                       = 1 << 6,   // Enforce the tab position to the left of the tab bar (after the tab list popup button)
    ImGuiTabItemFlags_Trailing                      = 1 << 7    // Enforce the tab position to the right of the tab bar (before the scrolling buttons)
};

// Flags for ImGui::BeginTable()
// [BETA API] API may evolve slightly! If you use this, please update to the next version when it comes out!
// - Important! Sizing policies have complex and subtle side effects, more so than you would expect.
//   Read comments/demos carefully + experiment with live demos to get acquainted with them.
// - The DEFAULT sizing policies are:
//    - Default to ImGuiTableFlags_SizingFixedFit    if ScrollX is on, or if host window has ImGuiWindowFlags_AlwaysAutoResize.
//    - Default to ImGuiTableFlags_SizingStretchSame if ScrollX is off.
// - When ScrollX is off:
//    - Table defaults to ImGuiTableFlags_SizingStretchSame -> all Columns defaults to ImGuiTableColumnFlags_WidthStretch with same weight.
//    - Columns sizing policy allowed: Stretch (default), Fixed/Auto.
//    - Fixed Columns will generally obtain their requested width (unless the table cannot fit them all).
//    - Stretch Columns will share the remaining width.
//    - Mixed Fixed/Stretch columns is possible but has various side-effects on resizing behaviors.
//      The typical use of mixing sizing policies is: any number of LEADING Fixed columns, followed by one or two TRAILING Stretch columns.
//      (this is because the visible order of columns have subtle but necessary effects on how they react to manual resizing).
// - When ScrollX is on:
//    - Table defaults to ImGuiTableFlags_SizingFixedFit -> all Columns defaults to ImGuiTableColumnFlags_WidthFixed
//    - Columns sizing policy allowed: Fixed/Auto mostly.
//    - Fixed Columns can be enlarged as needed. Table will show an horizontal scrollbar if needed.
//    - When using auto-resizing (non-resizable) fixed columns, querying the content width to use item right-alignment e.g. SetNextItemWidth(-FLT_MIN) doesn't make sense, would create a feedback loop.
//    - Using Stretch columns OFTEN DOES NOT MAKE SENSE if ScrollX is on, UNLESS you have specified a value for 'inner_width' in BeginTable().
//      If you specify a value for 'inner_width' then effectively the scrolling space is known and Stretch or mixed Fixed/Stretch columns become meaningful again.
// - Read on documentation at the top of imgui_tables.cpp for details.
enum ImGuiTableFlags_
{
    // Features
    ImGuiTableFlags_None                       = 0,
    ImGuiTableFlags_Resizable                  = 1 << 0,   // Enable resizing columns.
    ImGuiTableFlags_Reorderable                = 1 << 1,   // Enable reordering columns in header row (need calling TableSetupColumn() + TableHeadersRow() to display headers)
    ImGuiTableFlags_Hideable                   = 1 << 2,   // Enable hiding/disabling columns in context menu.
    ImGuiTableFlags_Sortable                   = 1 << 3,   // Enable sorting. Call TableGetSortSpecs() to obtain sort specs. Also see ImGuiTableFlags_SortMulti and ImGuiTableFlags_SortTristate.
    ImGuiTableFlags_NoSavedSettings            = 1 << 4,   // Disable persisting columns order, width and sort settings in the .ini file.
    ImGuiTableFlags_ContextMenuInBody          = 1 << 5,   // Right-click on columns body/contents will display table context menu. By default it is available in TableHeadersRow().
    // Decorations
    ImGuiTableFlags_RowBg                      = 1 << 6,   // Set each RowBg color with ImGuiCol_TableRowBg or ImGuiCol_TableRowBgAlt (equivalent of calling TableSetBgColor with ImGuiTableBgFlags_RowBg0 on each row manually)
    ImGuiTableFlags_BordersInnerH              = 1 << 7,   // Draw horizontal borders between rows.
    ImGuiTableFlags_BordersOuterH              = 1 << 8,   // Draw horizontal borders at the top and bottom.
    ImGuiTableFlags_BordersInnerV              = 1 << 9,   // Draw vertical borders between columns.
    ImGuiTableFlags_BordersOuterV              = 1 << 10,  // Draw vertical borders on the left and right sides.
    ImGuiTableFlags_BordersH                   = ImGuiTableFlags_BordersInnerH | ImGuiTableFlags_BordersOuterH, // Draw horizontal borders.
    ImGuiTableFlags_BordersV                   = ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_BordersOuterV, // Draw vertical borders.
    ImGuiTableFlags_BordersInner               = ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_BordersInnerH, // Draw inner borders.
    ImGuiTableFlags_BordersOuter               = ImGuiTableFlags_BordersOuterV | ImGuiTableFlags_BordersOuterH, // Draw outer borders.
    ImGuiTableFlags_Borders                    = ImGuiTableFlags_BordersInner | ImGuiTableFlags_BordersOuter,   // Draw all borders.
    ImGuiTableFlags_NoBordersInBody            = 1 << 11,  // [ALPHA] Disable vertical borders in columns Body (borders will always appears in Headers). -> May move to style
    ImGuiTableFlags_NoBordersInBodyUntilResize = 1 << 12,  // [ALPHA] Disable vertical borders in columns Body until hovered for resize (borders will always appears in Headers). -> May move to style
    // Sizing Policy (read above for defaults)
    ImGuiTableFlags_SizingFixedFit             = 1 << 13,  // Columns default to _WidthFixed or _WidthAuto (if resizable or not resizable), matching contents width.
    ImGuiTableFlags_SizingFixedSame            = 2 << 13,  // Columns default to _WidthFixed or _WidthAuto (if resizable or not resizable), matching the maximum contents width of all columns. Implicitly enable ImGuiTableFlags_NoKeepColumnsVisible.
    ImGuiTableFlags_SizingStretchProp          = 3 << 13,  // Columns default to _WidthStretch with default weights proportional to each columns contents widths.
    ImGuiTableFlags_SizingStretchSame          = 4 << 13,  // Columns default to _WidthStretch with default weights all equal, unless overridden by TableSetupColumn().
    // Sizing Extra Options
    ImGuiTableFlags_NoHostExtendX              = 1 << 16,  // Make outer width auto-fit to columns, overriding outer_size.x value. Only available when ScrollX/ScrollY are disabled and Stretch columns are not used.
    ImGuiTableFlags_NoHostExtendY              = 1 << 17,  // Make outer height stop exactly at outer_size.y (prevent auto-extending table past the limit). Only available when ScrollX/ScrollY are disabled. Data below the limit will be clipped and not visible.
    ImGuiTableFlags_NoKeepColumnsVisible       = 1 << 18,  // Disable keeping column always minimally visible when ScrollX is off and table gets too small. Not recommended if columns are resizable.
    ImGuiTableFlags_PreciseWidths              = 1 << 19,  // Disable distributing remainder width to stretched columns (width allocation on a 100-wide table with 3 columns: Without this flag: 33,33,34. With this flag: 33,33,33). With larger number of columns, resizing will appear to be less smooth.
    // Clipping
    ImGuiTableFlags_NoClip                     = 1 << 20,  // Disable clipping rectangle for every individual columns (reduce draw command count, items will be able to overflow into other columns). Generally incompatible with TableSetupScrollFreeze().
    // Padding
    ImGuiTableFlags_PadOuterX                  = 1 << 21,  // Default if BordersOuterV is on. Enable outer-most padding. Generally desirable if you have headers.
    ImGuiTableFlags_NoPadOuterX                = 1 << 22,  // Default if BordersOuterV is off. Disable outer-most padding.
    ImGuiTableFlags_NoPadInnerX                = 1 << 23,  // Disable inner padding between columns (double inner padding if BordersOuterV is on, single inner padding if BordersOuterV is off).
    // Scrolling
    ImGuiTableFlags_ScrollX                    = 1 << 24,  // Enable horizontal scrolling. Require 'outer_size' parameter of BeginTable() to specify the container size. Changes default sizing policy. Because this create a child window, ScrollY is currently generally recommended when using ScrollX.
    ImGuiTableFlags_ScrollY                    = 1 << 25,  // Enable vertical scrolling. Require 'outer_size' parameter of BeginTable() to specify the container size.
    // Sorting
    ImGuiTableFlags_SortMulti                  = 1 << 26,  // Hold shift when clicking headers to sort on multiple column. TableGetSortSpecs() may return specs where (SpecsCount > 1).
    ImGuiTableFlags_SortTristate               = 1 << 27,  // Allow no sorting, disable default sorting. TableGetSortSpecs() may return specs where (SpecsCount == 0).

    // [Internal] Combinations and masks
    ImGuiTableFlags_SizingMask_                = ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_SizingFixedSame | ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_SizingStretchSame

    // Obsolete names (will be removed soon)
#ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
    //, ImGuiTableFlags_ColumnsWidthFixed = ImGuiTableFlags_SizingFixedFit, ImGuiTableFlags_ColumnsWidthStretch = ImGuiTableFlags_SizingStretchSame   // WIP Tables 2020/12
    //, ImGuiTableFlags_SizingPolicyFixed = ImGuiTableFlags_SizingFixedFit, ImGuiTableFlags_SizingPolicyStretch = ImGuiTableFlags_SizingStretchSame   // WIP Tables 2021/01
#endif
};

// Flags for ImGui::TableSetupColumn()
enum ImGuiTableColumnFlags_
{
    // Input configuration flags
    ImGuiTableColumnFlags_None                  = 0,
    ImGuiTableColumnFlags_Disabled              = 1 << 0,   // Overriding/master disable flag: hide column, won't show in context menu (unlike calling TableSetColumnEnabled() which manipulates the user accessible state)
    ImGuiTableColumnFlags_DefaultHide           = 1 << 1,   // Default as a hidden/disabled column.
    ImGuiTableColumnFlags_DefaultSort           = 1 << 2,   // Default as a sorting column.
    ImGuiTableColumnFlags_WidthStretch          = 1 << 3,   // Column will stretch. Preferable with horizontal scrolling disabled (default if table sizing policy is _SizingStretchSame or _SizingStretchProp).
    ImGuiTableColumnFlags_WidthFixed            = 1 << 4,   // Column will not stretch. Preferable with horizontal scrolling enabled (default if table sizing policy is _SizingFixedFit and table is resizable).
    ImGuiTableColumnFlags_NoResize              = 1 << 5,   // Disable manual resizing.
    ImGuiTableColumnFlags_NoReorder             = 1 << 6,   // Disable manual reordering this column, this will also prevent other columns from crossing over this column.
    ImGuiTableColumnFlags_NoHide                = 1 << 7,   // Disable ability to hide/disable this column.
    ImGuiTableColumnFlags_NoClip                = 1 << 8,   // Disable clipping for this column (all NoClip columns will render in a same draw command).
    ImGuiTableColumnFlags_NoSort                = 1 << 9,   // Disable ability to sort on this field (even if ImGuiTableFlags_Sortable is set on the table).
    ImGuiTableColumnFlags_NoSortAscending       = 1 << 10,  // Disable ability to sort in the ascending direction.
    ImGuiTableColumnFlags_NoSortDescending      = 1 << 11,  // Disable ability to sort in the descending direction.
    ImGuiTableColumnFlags_NoHeaderLabel         = 1 << 12,  // TableHeadersRow() will not submit label for this column. Convenient for some small columns. Name will still appear in context menu.
    ImGuiTableColumnFlags_NoHeaderWidth         = 1 << 13,  // Disable header text width contribution to automatic column width.
    ImGuiTableColumnFlags_PreferSortAscending   = 1 << 14,  // Make the initial sort direction Ascending when first sorting on this column (default).
    ImGuiTableColumnFlags_PreferSortDescending  = 1 << 15,  // Make the initial sort direction Descending when first sorting on this column.
    ImGuiTableColumnFlags_IndentEnable          = 1 << 16,  // Use current Indent value when entering cell (default for column 0).
    ImGuiTableColumnFlags_IndentDisable         = 1 << 17,  // Ignore current Indent value when entering cell (default for columns > 0). Indentation changes _within_ the cell will still be honored.

    // Output status flags, read-only via TableGetColumnFlags()
    ImGuiTableColumnFlags_IsEnabled             = 1 << 24,  // Status: is enabled == not hidden by user/api (referred to as "Hide" in _DefaultHide and _NoHide) flags.
    ImGuiTableColumnFlags_IsVisible             = 1 << 25,  // Status: is visible == is enabled AND not clipped by scrolling.
    ImGuiTableColumnFlags_IsSorted              = 1 << 26,  // Status: is currently part of the sort specs
    ImGuiTableColumnFlags_IsHovered             = 1 << 27,  // Status: is hovered by mouse

    // [Internal] Combinations and masks
    ImGuiTableColumnFlags_WidthMask_            = ImGuiTableColumnFlags_WidthStretch | ImGuiTableColumnFlags_WidthFixed,
    ImGuiTableColumnFlags_IndentMask_           = ImGuiTableColumnFlags_IndentEnable | ImGuiTableColumnFlags_IndentDisable,
    ImGuiTableColumnFlags_StatusMask_           = ImGuiTableColumnFlags_IsEnabled | ImGuiTableColumnFlags_IsVisible | ImGuiTableColumnFlags_IsSorted | ImGuiTableColumnFlags_IsHovered,
    ImGuiTableColumnFlags_NoDirectResize_       = 1 << 30   // [Internal] Disable user resizing this column directly (it may however we resized indirectly from its left edge)

    // Obsolete names (will be removed soon)
#ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
    //ImGuiTableColumnFlags_WidthAuto           = ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoResize, // Column will not stretch and keep resizing based on submitted contents.
#endif
};

// Flags for ImGui::TableNextRow()
enum ImGuiTableRowFlags_
{
    ImGuiTableRowFlags_None                         = 0,
    ImGuiTableRowFlags_Headers                      = 1 << 0    // Identify header row (set default background color + width of its contents accounted different for auto column width)
};

// Enum for ImGui::TableSetBgColor()
// Background colors are rendering in 3 layers:
//  - Layer 0: draw with RowBg0 color if set, otherwise draw with ColumnBg0 if set.
//  - Layer 1: draw with RowBg1 color if set, otherwise draw with ColumnBg1 if set.
//  - Layer 2: draw with CellBg color if set.
// The purpose of the two row/columns layers is to let you decide if a background color changes should override or blend with the existing color.
// When using ImGuiTableFlags_RowBg on the table, each row has the RowBg0 color automatically set for odd/even rows.
// If you set the color of RowBg0 target, your color will override the existing RowBg0 color.
// If you set the color of RowBg1 or ColumnBg1 target, your color will blend over the RowBg0 color.
enum ImGuiTableBgTarget_
{
    ImGuiTableBgTarget_None                         = 0,
    ImGuiTableBgTarget_RowBg0                       = 1,        // Set row background color 0 (generally used for background, automatically set when ImGuiTableFlags_RowBg is used)
    ImGuiTableBgTarget_RowBg1                       = 2,        // Set row background color 1 (generally used for selection marking)
    ImGuiTableBgTarget_CellBg                       = 3         // Set cell background color (top-most color)
};

// Flags for ImGui::IsWindowFocused()
enum ImGuiFocusedFlags_
{
    ImGuiFocusedFlags_None                          = 0,
    ImGuiFocusedFlags_ChildWindows                  = 1 << 0,   // Return true if any children of the window is focused
    ImGuiFocusedFlags_RootWindow                    = 1 << 1,   // Test from root window (top most parent of the current hierarchy)
    ImGuiFocusedFlags_AnyWindow                     = 1 << 2,   // Return true if any window is focused. Important: If you are trying to tell how to dispatch your low-level inputs, do NOT use this. Use 'io.WantCaptureMouse' instead! Please read the FAQ!
    ImGuiFocusedFlags_NoPopupHierarchy              = 1 << 3,   // Do not consider popup hierarchy (do not treat popup emitter as parent of popup) (when used with _ChildWindows or _RootWindow)
    //ImGuiFocusedFlags_DockHierarchy               = 1 << 4,   // Consider docking hierarchy (treat dockspace host as parent of docked window) (when used with _ChildWindows or _RootWindow)
    ImGuiFocusedFlags_RootAndChildWindows           = ImGuiFocusedFlags_RootWindow | ImGuiFocusedFlags_ChildWindows
};

// Flags for ImGui::IsItemHovered(), ImGui::IsWindowHovered()
// Note: if you are trying to check whether your mouse should be dispatched to Dear ImGui or to your app, you should use 'io.WantCaptureMouse' instead! Please read the FAQ!
// Note: windows with the ImGuiWindowFlags_NoInputs flag are ignored by IsWindowHovered() calls.
enum ImGuiHoveredFlags_
{
    ImGuiHoveredFlags_None                          = 0,        // Return true if directly over the item/window, not obstructed by another window, not obstructed by an active popup or modal blocking inputs under them.
    ImGuiHoveredFlags_ChildWindows                  = 1 << 0,   // IsWindowHovered() only: Return true if any children of the window is hovered
    ImGuiHoveredFlags_RootWindow                    = 1 << 1,   // IsWindowHovered() only: Test from root window (top most parent of the current hierarchy)
    ImGuiHoveredFlags_AnyWindow                     = 1 << 2,   // IsWindowHovered() only: Return true if any window is hovered
    ImGuiHoveredFlags_NoPopupHierarchy              = 1 << 3,   // IsWindowHovered() only: Do not consider popup hierarchy (do not treat popup emitter as parent of popup) (when used with _ChildWindows or _RootWindow)
    //ImGuiHoveredFlags_DockHierarchy               = 1 << 4,   // IsWindowHovered() only: Consider docking hierarchy (treat dockspace host as parent of docked window) (when used with _ChildWindows or _RootWindow)
    ImGuiHoveredFlags_AllowWhenBlockedByPopup       = 1 << 5,   // Return true even if a popup window is normally blocking access to this item/window
    //ImGuiHoveredFlags_AllowWhenBlockedByModal     = 1 << 6,   // Return true even if a modal popup window is normally blocking access to this item/window. FIXME-TODO: Unavailable yet.
    ImGuiHoveredFlags_AllowWhenBlockedByActiveItem  = 1 << 7,   // Return true even if an active item is blocking access to this item/window. Useful for Drag and Drop patterns.
    ImGuiHoveredFlags_AllowWhenOverlapped           = 1 << 8,   // IsItemHovered() only: Return true even if the position is obstructed or overlapped by another window
    ImGuiHoveredFlags_AllowWhenDisabled             = 1 << 9,   // IsItemHovered() only: Return true even if the item is disabled
    ImGuiHoveredFlags_RectOnly                      = ImGuiHoveredFlags_AllowWhenBlockedByPopup | ImGuiHoveredFlags_AllowWhenBlockedByActiveItem | ImGuiHoveredFlags_AllowWhenOverlapped,
    ImGuiHoveredFlags_RootAndChildWindows           = ImGuiHoveredFlags_RootWindow | ImGuiHoveredFlags_ChildWindows
};

// Flags for ImGui::BeginDragDropSource(), ImGui::AcceptDragDropPayload()
enum ImGuiDragDropFlags_
{
    ImGuiDragDropFlags_None                         = 0,
    // BeginDragDropSource() flags
    ImGuiDragDropFlags_SourceNoPreviewTooltip       = 1 << 0,   // By default, a successful call to BeginDragDropSource opens a tooltip so you can display a preview or description of the source contents. This flag disable this behavior.
    ImGuiDragDropFlags_SourceNoDisableHover         = 1 << 1,   // By default, when dragging we clear data so that IsItemHovered() will return false, to avoid subsequent user code submitting tooltips. This flag disable this behavior so you can still call IsItemHovered() on the source item.
    ImGuiDragDropFlags_SourceNoHoldToOpenOthers     = 1 << 2,   // Disable the behavior that allows to open tree nodes and collapsing header by holding over them while dragging a source item.
    ImGuiDragDropFlags_SourceAllowNullID            = 1 << 3,   // Allow items such as Text(), Image() that have no unique identifier to be used as drag source, by manufacturing a temporary identifier based on their window-relative position. This is extremely unusual within the dear imgui ecosystem and so we made it explicit.
    ImGuiDragDropFlags_SourceExtern                 = 1 << 4,   // External source (from outside of dear imgui), won't attempt to read current item/window info. Will always return true. Only one Extern source can be active simultaneously.
    ImGuiDragDropFlags_SourceAutoExpirePayload      = 1 << 5,   // Automatically expire the payload if the source cease to be submitted (otherwise payloads are persisting while being dragged)
    // AcceptDragDropPayload() flags
    ImGuiDragDropFlags_AcceptBeforeDelivery         = 1 << 10,  // AcceptDragDropPayload() will returns true even before the mouse button is released. You can then call IsDelivery() to test if the payload needs to be delivered.
    ImGuiDragDropFlags_AcceptNoDrawDefaultRect      = 1 << 11,  // Do not draw the default highlight rectangle when hovering over target.
    ImGuiDragDropFlags_AcceptNoPreviewTooltip       = 1 << 12,  // Request hiding the BeginDragDropSource tooltip from the BeginDragDropTarget site.
    ImGuiDragDropFlags_AcceptPeekOnly               = ImGuiDragDropFlags_AcceptBeforeDelivery | ImGuiDragDropFlags_AcceptNoDrawDefaultRect  // For peeking ahead and inspecting the payload before delivery.
};

// Standard Drag and Drop payload types. You can define you own payload types using short strings. Types starting with '_' are defined by Dear ImGui.
#define IMGUI_PAYLOAD_TYPE_COLOR_3F     "_COL3F"    // float[3]: Standard type for colors, without alpha. User code may use this type.
#define IMGUI_PAYLOAD_TYPE_COLOR_4F     "_COL4F"    // float[4]: Standard type for colors. User code may use this type.

// A primary data type
enum ImGuiDataType_
{
    ImGuiDataType_S8,       // signed char / char (with sensible compilers)
    ImGuiDataType_U8,       // unsigned char
    ImGuiDataType_S16,      // short
    ImGuiDataType_U16,      // unsigned short
    ImGuiDataType_S32,      // int
    ImGuiDataType_U32,      // unsigned int
    ImGuiDataType_S64,      // long long / __int64
    ImGuiDataType_U64,      // unsigned long long / unsigned __int64
    ImGuiDataType_Float,    // float
    ImGuiDataType_Double,   // double
    ImGuiDataType_COUNT
};

// A cardinal direction
enum ImGuiDir_
{
    ImGuiDir_None    = -1,
    ImGuiDir_Left    = 0,
    ImGuiDir_Right   = 1,
    ImGuiDir_Up      = 2,
    ImGuiDir_Down    = 3,
    ImGuiDir_COUNT
};

// A sorting direction
enum ImGuiSortDirection_
{
    ImGuiSortDirection_None         = 0,
    ImGuiSortDirection_Ascending    = 1,    // Ascending = 0->9, A->Z etc.
    ImGuiSortDirection_Descending   = 2     // Descending = 9->0, Z->A etc.
};

// User fill ImGuiIO.KeyMap[] array with indices into the ImGuiIO.KeysDown[512] array
enum ImGuiKey_ : int
{
    // Keyboard
    ImGuiKey_None = 0,
    ImGuiKey_Tab = 512,             // == ImGuiKey_NamedKey_BEGIN
    ImGuiKey_LeftArrow,
    ImGuiKey_RightArrow,
    ImGuiKey_UpArrow,
    ImGuiKey_DownArrow,
    ImGuiKey_PageUp,
    ImGuiKey_PageDown,
    ImGuiKey_Home,
    ImGuiKey_End,
    ImGuiKey_Insert,
    ImGuiKey_Delete,
    ImGuiKey_Backspace,
    ImGuiKey_Space,
    ImGuiKey_Enter,
    ImGuiKey_Escape,
    ImGuiKey_LeftCtrl, ImGuiKey_LeftShift, ImGuiKey_LeftAlt, ImGuiKey_LeftSuper,
    ImGuiKey_RightCtrl, ImGuiKey_RightShift, ImGuiKey_RightAlt, ImGuiKey_RightSuper,
    ImGuiKey_Menu,
    ImGuiKey_0, ImGuiKey_1, ImGuiKey_2, ImGuiKey_3, ImGuiKey_4, ImGuiKey_5, ImGuiKey_6, ImGuiKey_7, ImGuiKey_8, ImGuiKey_9,
    ImGuiKey_A, ImGuiKey_B, ImGuiKey_C, ImGuiKey_D, ImGuiKey_E, ImGuiKey_F, ImGuiKey_G, ImGuiKey_H, ImGuiKey_I, ImGuiKey_J,
    ImGuiKey_K, ImGuiKey_L, ImGuiKey_M, ImGuiKey_N, ImGuiKey_O, ImGuiKey_P, ImGuiKey_Q, ImGuiKey_R, ImGuiKey_S, ImGuiKey_T,
    ImGuiKey_U, ImGuiKey_V, ImGuiKey_W, ImGuiKey_X, ImGuiKey_Y, ImGuiKey_Z,
    ImGuiKey_F1, ImGuiKey_F2, ImGuiKey_F3, ImGuiKey_F4, ImGuiKey_F5, ImGuiKey_F6,
    ImGuiKey_F7, ImGuiKey_F8, ImGuiKey_F9, ImGuiKey_F10, ImGuiKey_F11, ImGuiKey_F12,
    ImGuiKey_Apostrophe,        // '
    ImGuiKey_Comma,             // ,
    ImGuiKey_Minus,             // -
    ImGuiKey_Period,            // .
    ImGuiKey_Slash,             // /
    ImGuiKey_Semicolon,         // ;
    ImGuiKey_Equal,             // =
    ImGuiKey_LeftBracket,       // [
    ImGuiKey_Backslash,         // \ (this text inhibit multiline comment caused by backslash)
    ImGuiKey_RightBracket,      // ]
    ImGuiKey_GraveAccent,       // `
    ImGuiKey_CapsLock,
    ImGuiKey_ScrollLock,
    ImGuiKey_NumLock,
    ImGuiKey_PrintScreen,
    ImGuiKey_Pause,
    ImGuiKey_Keypad0, ImGuiKey_Keypad1, ImGuiKey_Keypad2, ImGuiKey_Keypad3, ImGuiKey_Keypad4,
    ImGuiKey_Keypad5, ImGuiKey_Keypad6, ImGuiKey_Keypad7, ImGuiKey_Keypad8, ImGuiKey_Keypad9,
    ImGuiKey_KeypadDecimal,
    ImGuiKey_KeypadDivide,
    ImGuiKey_KeypadMultiply,
    ImGuiKey_KeypadSubtract,
    ImGuiKey_KeypadAdd,
    ImGuiKey_KeypadEnter,
    ImGuiKey_KeypadEqual,

    // Gamepad (some of those are analog values, 0.0f to 1.0f)                          // NAVIGATION ACTION
    // (download controller mapping PNG/PSD at http://dearimgui.com/controls_sheets)
    ImGuiKey_GamepadStart,          // Menu (Xbox)      + (Switch)   Start/Options (PS)
    ImGuiKey_GamepadBack,           // View (Xbox)      - (Switch)   Share (PS)
    ImGuiKey_GamepadFaceLeft,       // X (Xbox)         Y (Switch)   Square (PS)        // Tap: Toggle Menu. Hold: Windowing mode (Focus/Move/Resize windows)
    ImGuiKey_GamepadFaceRight,      // B (Xbox)         A (Switch)   Circle (PS)        // Cancel / Close / Exit
    ImGuiKey_GamepadFaceUp,         // Y (Xbox)         X (Switch)   Triangle (PS)      // Text Input / On-screen Keyboard
    ImGuiKey_GamepadFaceDown,       // A (Xbox)         B (Switch)   Cross (PS)         // Activate / Open / Toggle / Tweak
    ImGuiKey_GamepadDpadLeft,       // D-pad Left                                       // Move / Tweak / Resize Window (in Windowing mode)
    ImGuiKey_GamepadDpadRight,      // D-pad Right                                      // Move / Tweak / Resize Window (in Windowing mode)
    ImGuiKey_GamepadDpadUp,         // D-pad Up                                         // Move / Tweak / Resize Window (in Windowing mode)
    ImGuiKey_GamepadDpadDown,       // D-pad Down                                       // Move / Tweak / Resize Window (in Windowing mode)
    ImGuiKey_GamepadL1,             // L Bumper (Xbox)  L (Switch)   L1 (PS)            // Tweak Slower / Focus Previous (in Windowing mode)
    ImGuiKey_GamepadR1,             // R Bumper (Xbox)  R (Switch)   R1 (PS)            // Tweak Faster / Focus Next (in Windowing mode)
    ImGuiKey_GamepadL2,             // L Trig. (Xbox)   ZL (Switch)  L2 (PS) [Analog]
    ImGuiKey_GamepadR2,             // R Trig. (Xbox)   ZR (Switch)  R2 (PS) [Analog]
    ImGuiKey_GamepadL3,             // L Stick (Xbox)   L3 (Switch)  L3 (PS)
    ImGuiKey_GamepadR3,             // R Stick (Xbox)   R3 (Switch)  R3 (PS)
    ImGuiKey_GamepadLStickLeft,     // [Analog]                                         // Move Window (in Windowing mode)
    ImGuiKey_GamepadLStickRight,    // [Analog]                                         // Move Window (in Windowing mode)
    ImGuiKey_GamepadLStickUp,       // [Analog]                                         // Move Window (in Windowing mode)
    ImGuiKey_GamepadLStickDown,     // [Analog]                                         // Move Window (in Windowing mode)
    ImGuiKey_GamepadRStickLeft,     // [Analog]
    ImGuiKey_GamepadRStickRight,    // [Analog]
    ImGuiKey_GamepadRStickUp,       // [Analog]
    ImGuiKey_GamepadRStickDown,     // [Analog]

    // Aliases: Mouse Buttons (auto-submitted from AddMouseButtonEvent() calls)
    // - This is mirroring the data also written to io.MouseDown[], io.MouseWheel, in a format allowing them to be accessed via standard key API.
    ImGuiKey_MouseLeft, ImGuiKey_MouseRight, ImGuiKey_MouseMiddle, ImGuiKey_MouseX1, ImGuiKey_MouseX2, ImGuiKey_MouseWheelX, ImGuiKey_MouseWheelY,

    // [Internal] Reserved for mod storage
    ImGuiKey_ReservedForModCtrl, ImGuiKey_ReservedForModShift, ImGuiKey_ReservedForModAlt, ImGuiKey_ReservedForModSuper,
    ImGuiKey_COUNT,

    // Keyboard Modifiers (explicitly submitted by backend via AddKeyEvent() calls)
    // - This is mirroring the data also written to io.KeyCtrl, io.KeyShift, io.KeyAlt, io.KeySuper, in a format allowing
    //   them to be accessed via standard key API, allowing calls such as IsKeyPressed(), IsKeyReleased(), querying duration etc.
    // - Code polling every key (e.g. an interface to detect a key press for input mapping) might want to ignore those
    //   and prefer using the real keys (e.g. ImGuiKey_LeftCtrl, ImGuiKey_RightCtrl instead of ImGuiMod_Ctrl).
    // - In theory the value of keyboard modifiers should be roughly equivalent to a logical or of the equivalent left/right keys.
    //   In practice: it's complicated; mods are often provided from different sources. Keyboard layout, IME, sticky keys and
    //   backends tend to interfere and break that equivalence. The safer decision is to relay that ambiguity down to the end-user...
    ImGuiMod_None                   = 0,
    ImGuiMod_Ctrl                   = 1 << 12, // Ctrl
    ImGuiMod_Shift                  = 1 << 13, // Shift
    ImGuiMod_Alt                    = 1 << 14, // Option/Menu
    ImGuiMod_Super                  = 1 << 15, // Cmd/Super/Windows
    ImGuiMod_Shortcut               = 1 << 11, // Alias for Ctrl (non-macOS) _or_ Super (macOS).
    ImGuiMod_Mask_                  = 0xF800,  // 5-bits

    // [Internal] Prior to 1.87 we required user to fill io.KeysDown[512] using their own native index + the io.KeyMap[] array.
    // We are ditching this method but keeping a legacy path for user code doing e.g. IsKeyPressed(MY_NATIVE_KEY_CODE)
    // If you need to iterate all keys (for e.g. an input mapper) you may use ImGuiKey_NamedKey_BEGIN..ImGuiKey_NamedKey_END.
    ImGuiKey_NamedKey_BEGIN         = 512,
    ImGuiKey_NamedKey_END           = ImGuiKey_COUNT,
    ImGuiKey_NamedKey_COUNT         = ImGuiKey_NamedKey_END - ImGuiKey_NamedKey_BEGIN,
#ifdef IMGUI_DISABLE_OBSOLETE_KEYIO
    ImGuiKey_KeysData_SIZE          = ImGuiKey_NamedKey_COUNT,  // Size of KeysData[]: only hold named keys
    ImGuiKey_KeysData_OFFSET        = ImGuiKey_NamedKey_BEGIN,  // Accesses to io.KeysData[] must use (key - ImGuiKey_KeysData_OFFSET) index.
#else
    ImGuiKey_KeysData_SIZE          = ImGuiKey_COUNT,           // Size of KeysData[]: hold legacy 0..512 keycodes + named keys
    ImGuiKey_KeysData_OFFSET        = 0,                        // Accesses to io.KeysData[] must use (key - ImGuiKey_KeysData_OFFSET) index.
#endif

#ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
    ImGuiKey_ModCtrl = ImGuiMod_Ctrl, ImGuiKey_ModShift = ImGuiMod_Shift, ImGuiKey_ModAlt = ImGuiMod_Alt, ImGuiKey_ModSuper = ImGuiMod_Super, // Renamed in 1.89
    ImGuiKey_KeyPadEnter = ImGuiKey_KeypadEnter,    // Renamed in 1.87
#endif
};

// To test io.KeyMods (which is a combination of individual fields io.KeyCtrl, io.KeyShift, io.KeyAlt set by user/backend)
enum ImGuiKeyModFlags_
{
    ImGuiKeyModFlags_None       = 0,
    ImGuiKeyModFlags_Ctrl       = 1 << 0,
    ImGuiKeyModFlags_Shift      = 1 << 1,
    ImGuiKeyModFlags_Alt        = 1 << 2,
    ImGuiKeyModFlags_Super      = 1 << 3
};

// Gamepad/Keyboard navigation
// Keyboard: Set io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard to enable. NewFrame() will automatically fill io.NavInputs[] based on your io.KeysDown[] + io.KeyMap[] arrays.
// Gamepad:  Set io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad to enable. Backend: set ImGuiBackendFlags_HasGamepad and fill the io.NavInputs[] fields before calling NewFrame(). Note that io.NavInputs[] is cleared by EndFrame().
// Read instructions in imgui.cpp for more details. Download PNG/PSD at http://dearimgui.org/controls_sheets.
enum ImGuiNavInput_
{
    // Gamepad Mapping
    ImGuiNavInput_Activate,      // activate / open / toggle / tweak value       // e.g. Cross  (PS4), A (Xbox), A (Switch), Space (Keyboard)
    ImGuiNavInput_Cancel,        // cancel / close / exit                        // e.g. Circle (PS4), B (Xbox), B (Switch), Escape (Keyboard)
    ImGuiNavInput_Input,         // text input / on-screen keyboard              // e.g. Triang.(PS4), Y (Xbox), X (Switch), Return (Keyboard)
    ImGuiNavInput_Menu,          // tap: toggle menu / hold: focus, move, resize // e.g. Square (PS4), X (Xbox), Y (Switch), Alt (Keyboard)
    ImGuiNavInput_DpadLeft,      // move / tweak / resize window (w/ PadMenu)    // e.g. D-pad Left/Right/Up/Down (Gamepads), Arrow keys (Keyboard)
    ImGuiNavInput_DpadRight,     //
    ImGuiNavInput_DpadUp,        //
    ImGuiNavInput_DpadDown,      //
    ImGuiNavInput_LStickLeft,    // scroll / move window (w/ PadMenu)            // e.g. Left Analog Stick Left/Right/Up/Down
    ImGuiNavInput_LStickRight,   //
    ImGuiNavInput_LStickUp,      //
    ImGuiNavInput_LStickDown,    //
    ImGuiNavInput_FocusPrev,     // next window (w/ PadMenu)                     // e.g. L1 or L2 (PS4), LB or LT (Xbox), L or ZL (Switch)
    ImGuiNavInput_FocusNext,     // prev window (w/ PadMenu)                     // e.g. R1 or R2 (PS4), RB or RT (Xbox), R or ZL (Switch)
    ImGuiNavInput_TweakSlow,     // slower tweaks                                // e.g. L1 or L2 (PS4), LB or LT (Xbox), L or ZL (Switch)
    ImGuiNavInput_TweakFast,     // faster tweaks                                // e.g. R1 or R2 (PS4), RB or RT (Xbox), R or ZL (Switch)

    // [Internal] Don't use directly! This is used internally to differentiate keyboard from gamepad inputs for behaviors that require to differentiate them.
    // Keyboard behavior that have no corresponding gamepad mapping (e.g. CTRL+TAB) will be directly reading from io.KeysDown[] instead of io.NavInputs[].
    ImGuiNavInput_KeyLeft_,      // move left                                    // = Arrow keys
    ImGuiNavInput_KeyRight_,     // move right
    ImGuiNavInput_KeyUp_,        // move up
    ImGuiNavInput_KeyDown_,      // move down
    ImGuiNavInput_COUNT,
    ImGuiNavInput_InternalStart_ = ImGuiNavInput_KeyLeft_
};

// Configuration flags stored in io.ConfigFlags. Set by user/application.
enum ImGuiConfigFlags_
{
    ImGuiConfigFlags_None                   = 0,
    ImGuiConfigFlags_NavEnableKeyboard      = 1 << 0,   // Master keyboard navigation enable flag. NewFrame() will automatically fill io.NavInputs[] based on io.KeysDown[].
    ImGuiConfigFlags_NavEnableGamepad       = 1 << 1,   // Master gamepad navigation enable flag. This is mostly to instruct your imgui backend to fill io.NavInputs[]. Backend also needs to set ImGuiBackendFlags_HasGamepad.
    ImGuiConfigFlags_NavEnableSetMousePos   = 1 << 2,   // Instruct navigation to move the mouse cursor. May be useful on TV/console systems where moving a virtual mouse is awkward. Will update io.MousePos and set io.WantSetMousePos=true. If enabled you MUST honor io.WantSetMousePos requests in your backend, otherwise ImGui will react as if the mouse is jumping around back and forth.
    ImGuiConfigFlags_NavNoCaptureKeyboard   = 1 << 3,   // Instruct navigation to not set the io.WantCaptureKeyboard flag when io.NavActive is set.
    ImGuiConfigFlags_NoMouse                = 1 << 4,   // Instruct imgui to clear mouse position/buttons in NewFrame(). This allows ignoring the mouse information set by the backend.
    ImGuiConfigFlags_NoMouseCursorChange    = 1 << 5,   // Instruct backend to not alter mouse cursor shape and visibility. Use if the backend cursor changes are interfering with yours and you don't want to use SetMouseCursor() to change mouse cursor. You may want to honor requests from imgui by reading GetMouseCursor() yourself instead.

    // User storage (to allow your backend/engine to communicate to code that may be shared between multiple projects. Those flags are not used by core Dear ImGui)
    ImGuiConfigFlags_IsSRGB                 = 1 << 20,  // Application is SRGB-aware.
    ImGuiConfigFlags_IsTouchScreen          = 1 << 21   // Application is using a touch screen instead of a mouse.
};

// Backend capabilities flags stored in io.BackendFlags. Set by imgui_impl_xxx or custom backend.
enum ImGuiBackendFlags_
{
    ImGuiBackendFlags_None                  = 0,
    ImGuiBackendFlags_HasGamepad            = 1 << 0,   // Backend Platform supports gamepad and currently has one connected.
    ImGuiBackendFlags_HasMouseCursors       = 1 << 1,   // Backend Platform supports honoring GetMouseCursor() value to change the OS cursor shape.
    ImGuiBackendFlags_HasSetMousePos        = 1 << 2,   // Backend Platform supports io.WantSetMousePos requests to reposition the OS mouse position (only used if ImGuiConfigFlags_NavEnableSetMousePos is set).
    ImGuiBackendFlags_RendererHasVtxOffset  = 1 << 3    // Backend Renderer supports ImDrawCmd::VtxOffset. This enables output of large meshes (64K+ vertices) while still using 16-bit indices.
};

// Enumeration for PushStyleColor() / PopStyleColor()
enum ImGuiCol_
{
    ImGuiCol_Text,
    ImGuiCol_TextDisabled,
    ImGuiCol_WindowBg,              // Background of normal windows
    ImGuiCol_ChildBg,               // Background of child windows
    ImGuiCol_PopupBg,               // Background of popups, menus, tooltips windows
    ImGuiCol_Border,
    ImGuiCol_BorderShadow,
    ImGuiCol_FrameBg,               // Background of checkbox, radio button, plot, slider, text input
    ImGuiCol_FrameBgHovered,
    ImGuiCol_FrameBgActive,
    ImGuiCol_TitleBg,
    ImGuiCol_TitleBgActive,
    ImGuiCol_TitleBgCollapsed,
    ImGuiCol_MenuBarBg,
    ImGuiCol_ScrollbarBg,
    ImGuiCol_ScrollbarGrab,
    ImGuiCol_ScrollbarGrabHovered,
    ImGuiCol_ScrollbarGrabActive,
    ImGuiCol_CheckMark,
    ImGuiCol_SliderGrab,
    ImGuiCol_SliderGrabActive,
    ImGuiCol_Button,
    ImGuiCol_ButtonHovered,
    ImGuiCol_ButtonActive,
    ImGuiCol_Header,                // Header* colors are used for CollapsingHeader, TreeNode, Selectable, MenuItem
    ImGuiCol_HeaderHovered,
    ImGuiCol_HeaderActive,
    ImGuiCol_Separator,
    ImGuiCol_SeparatorHovered,
    ImGuiCol_SeparatorActive,
    ImGuiCol_ResizeGrip,
    ImGuiCol_ResizeGripHovered,
    ImGuiCol_ResizeGripActive,
    ImGuiCol_Tab,
    ImGuiCol_TabHovered,
    ImGuiCol_TabActive,
    ImGuiCol_TabUnfocused,
    ImGuiCol_TabUnfocusedActive,
    ImGuiCol_PlotLines,
    ImGuiCol_PlotLinesHovered,
    ImGuiCol_PlotHistogram,
    ImGuiCol_PlotHistogramHovered,
    ImGuiCol_TableHeaderBg,         // Table header background
    ImGuiCol_TableBorderStrong,     // Table outer and header borders (prefer using Alpha=1.0 here)
    ImGuiCol_TableBorderLight,      // Table inner borders (prefer using Alpha=1.0 here)
    ImGuiCol_TableRowBg,            // Table row background (even rows)
    ImGuiCol_TableRowBgAlt,         // Table row background (odd rows)
    ImGuiCol_TextSelectedBg,
    ImGuiCol_DragDropTarget,
    ImGuiCol_NavHighlight,          // Gamepad/keyboard: current highlighted item
    ImGuiCol_NavWindowingHighlight, // Highlight window when using CTRL+TAB
    ImGuiCol_NavWindowingDimBg,     // Darken/colorize entire screen behind the CTRL+TAB window list, when active
    ImGuiCol_ModalWindowDimBg,      // Darken/colorize entire screen behind a modal window, when one is active
    ImGuiCol_COUNT
};

// Enumeration for PushStyleVar() / PopStyleVar() to temporarily modify the ImGuiStyle structure.
// - The enum only refers to fields of ImGuiStyle which makes sense to be pushed/popped inside UI code.
//   During initialization or between frames, feel free to just poke into ImGuiStyle directly.
// - Tip: Use your programming IDE navigation facilities on the names in the _second column_ below to find the actual members and their description.
//   In Visual Studio IDE: CTRL+comma ("Edit.NavigateTo") can follow symbols in comments, whereas CTRL+F12 ("Edit.GoToImplementation") cannot.
//   With Visual Assist installed: ALT+G ("VAssistX.GoToImplementation") can also follow symbols in comments.
// - When changing this enum, you need to update the associated internal table GStyleVarInfo[] accordingly. This is where we link enum values to members offset/type.
enum ImGuiStyleVar_
{
    // Enum name --------------------- // Member in ImGuiStyle structure (see ImGuiStyle for descriptions)
    ImGuiStyleVar_Alpha,               // float     Alpha
    ImGuiStyleVar_DisabledAlpha,       // float     DisabledAlpha
    ImGuiStyleVar_WindowPadding,       // ImVec2    WindowPadding
    ImGuiStyleVar_WindowRounding,      // float     WindowRounding
    ImGuiStyleVar_WindowBorderSize,    // float     WindowBorderSize
    ImGuiStyleVar_WindowMinSize,       // ImVec2    WindowMinSize
    ImGuiStyleVar_WindowTitleAlign,    // ImVec2    WindowTitleAlign
    ImGuiStyleVar_ChildRounding,       // float     ChildRounding
    ImGuiStyleVar_ChildBorderSize,     // float     ChildBorderSize
    ImGuiStyleVar_PopupRounding,       // float     PopupRounding
    ImGuiStyleVar_PopupBorderSize,     // float     PopupBorderSize
    ImGuiStyleVar_FramePadding,        // ImVec2    FramePadding
    ImGuiStyleVar_FrameRounding,       // float     FrameRounding
    ImGuiStyleVar_FrameBorderSize,     // float     FrameBorderSize
    ImGuiStyleVar_ItemSpacing,         // ImVec2    ItemSpacing
    ImGuiStyleVar_ItemInnerSpacing,    // ImVec2    ItemInnerSpacing
    ImGuiStyleVar_IndentSpacing,       // float     IndentSpacing
    ImGuiStyleVar_CellPadding,         // ImVec2    CellPadding
    ImGuiStyleVar_ScrollbarSize,       // float     ScrollbarSize
    ImGuiStyleVar_ScrollbarRounding,   // float     ScrollbarRounding
    ImGuiStyleVar_GrabMinSize,         // float     GrabMinSize
    ImGuiStyleVar_GrabRounding,        // float     GrabRounding
    ImGuiStyleVar_TabRounding,         // float     TabRounding
    ImGuiStyleVar_ButtonTextAlign,     // ImVec2    ButtonTextAlign
    ImGuiStyleVar_SelectableTextAlign, // ImVec2    SelectableTextAlign
    ImGuiStyleVar_COUNT
};

// Flags for InvisibleButton() [extended in imgui_internal.h]
enum ImGuiButtonFlags_
{
    ImGuiButtonFlags_None                   = 0,
    ImGuiButtonFlags_MouseButtonLeft        = 1 << 0,   // React on left mouse button (default)
    ImGuiButtonFlags_MouseButtonRight       = 1 << 1,   // React on right mouse button
    ImGuiButtonFlags_MouseButtonMiddle      = 1 << 2,   // React on center mouse button

    // [Internal]
    ImGuiButtonFlags_MouseButtonMask_       = ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight | ImGuiButtonFlags_MouseButtonMiddle,
    ImGuiButtonFlags_MouseButtonDefault_    = ImGuiButtonFlags_MouseButtonLeft
};

// Flags for ColorEdit3() / ColorEdit4() / ColorPicker3() / ColorPicker4() / ColorButton()
enum ImGuiColorEditFlags_
{
    ImGuiColorEditFlags_None            = 0,
    ImGuiColorEditFlags_NoAlpha         = 1 << 1,   //              // ColorEdit, ColorPicker, ColorButton: ignore Alpha component (will only read 3 components from the input pointer).
    ImGuiColorEditFlags_NoPicker        = 1 << 2,   //              // ColorEdit: disable picker when clicking on color square.
    ImGuiColorEditFlags_NoOptions       = 1 << 3,   //              // ColorEdit: disable toggling options menu when right-clicking on inputs/small preview.
    ImGuiColorEditFlags_NoSmallPreview  = 1 << 4,   //              // ColorEdit, ColorPicker: disable color square preview next to the inputs. (e.g. to show only the inputs)
    ImGuiColorEditFlags_NoInputs        = 1 << 5,   //              // ColorEdit, ColorPicker: disable inputs sliders/text widgets (e.g. to show only the small preview color square).
    ImGuiColorEditFlags_NoTooltip       = 1 << 6,   //              // ColorEdit, ColorPicker, ColorButton: disable tooltip when hovering the preview.
    ImGuiColorEditFlags_NoLabel         = 1 << 7,   //              // ColorEdit, ColorPicker: disable display of inline text label (the label is still forwarded to the tooltip and picker).
    ImGuiColorEditFlags_NoSidePreview   = 1 << 8,   //              // ColorPicker: disable bigger color preview on right side of the picker, use small color square preview instead.
    ImGuiColorEditFlags_NoDragDrop      = 1 << 9,   //              // ColorEdit: disable drag and drop target. ColorButton: disable drag and drop source.
    ImGuiColorEditFlags_NoBorder        = 1 << 10,  //              // ColorButton: disable border (which is enforced by default)

    // User Options (right-click on widget to change some of them).
    ImGuiColorEditFlags_AlphaBar        = 1 << 16,  //              // ColorEdit, ColorPicker: show vertical alpha bar/gradient in picker.
    ImGuiColorEditFlags_AlphaPreview    = 1 << 17,  //              // ColorEdit, ColorPicker, ColorButton: display preview as a transparent color over a checkerboard, instead of opaque.
    ImGuiColorEditFlags_AlphaPreviewHalf= 1 << 18,  //              // ColorEdit, ColorPicker, ColorButton: display half opaque / half checkerboard, instead of opaque.
    ImGuiColorEditFlags_HDR             = 1 << 19,  //              // (WIP) ColorEdit: Currently only disable 0.0f..1.0f limits in RGBA edition (note: you probably want to use ImGuiColorEditFlags_Float flag as well).
    ImGuiColorEditFlags_DisplayRGB      = 1 << 20,  // [Display]    // ColorEdit: override _display_ type among RGB/HSV/Hex. ColorPicker: select any combination using one or more of RGB/HSV/Hex.
    ImGuiColorEditFlags_DisplayHSV      = 1 << 21,  // [Display]    // "
    ImGuiColorEditFlags_DisplayHex      = 1 << 22,  // [Display]    // "
    ImGuiColorEditFlags_Uint8           = 1 << 23,  // [DataType]   // ColorEdit, ColorPicker, ColorButton: _display_ values formatted as 0..255.
    ImGuiColorEditFlags_Float           = 1 << 24,  // [DataType]   // ColorEdit, ColorPicker, ColorButton: _display_ values formatted as 0.0f..1.0f floats instead of 0..255 integers. No round-trip of value via integers.
    ImGuiColorEditFlags_PickerHueBar    = 1 << 25,  // [Picker]     // ColorPicker: bar for Hue, rectangle for Sat/Value.
    ImGuiColorEditFlags_PickerHueWheel  = 1 << 26,  // [Picker]     // ColorPicker: wheel for Hue, triangle for Sat/Value.
    ImGuiColorEditFlags_InputRGB        = 1 << 27,  // [Input]      // ColorEdit, ColorPicker: input and output data in RGB format.
    ImGuiColorEditFlags_InputHSV        = 1 << 28,  // [Input]      // ColorEdit, ColorPicker: input and output data in HSV format.

    // Defaults Options. You can set application defaults using SetColorEditOptions(). The intent is that you probably don't want to
    // override them in most of your calls. Let the user choose via the option menu and/or call SetColorEditOptions() once during startup.
    ImGuiColorEditFlags_DefaultOptions_ = ImGuiColorEditFlags_Uint8 | ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_PickerHueBar,

    // [Internal] Masks
    ImGuiColorEditFlags_DisplayMask_    = ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_DisplayHSV | ImGuiColorEditFlags_DisplayHex,
    ImGuiColorEditFlags_DataTypeMask_   = ImGuiColorEditFlags_Uint8 | ImGuiColorEditFlags_Float,
    ImGuiColorEditFlags_PickerMask_     = ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_PickerHueBar,
    ImGuiColorEditFlags_InputMask_      = ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_InputHSV

    // Obsolete names (will be removed)
#ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
    , ImGuiColorEditFlags_RGB = ImGuiColorEditFlags_DisplayRGB, ImGuiColorEditFlags_HSV = ImGuiColorEditFlags_DisplayHSV, ImGuiColorEditFlags_HEX = ImGuiColorEditFlags_DisplayHex  // [renamed in 1.69]
#endif
};

// Flags for DragFloat(), DragInt(), SliderFloat(), SliderInt() etc.
// We use the same sets of flags for DragXXX() and SliderXXX() functions as the features are the same and it makes it easier to swap them.
enum ImGuiSliderFlags_
{
    ImGuiSliderFlags_None                   = 0,
    ImGuiSliderFlags_AlwaysClamp            = 1 << 4,       // Clamp value to min/max bounds when input manually with CTRL+Click. By default CTRL+Click allows going out of bounds.
    ImGuiSliderFlags_Logarithmic            = 1 << 5,       // Make the widget logarithmic (linear otherwise). Consider using ImGuiSliderFlags_NoRoundToFormat with this if using a format-string with small amount of digits.
    ImGuiSliderFlags_NoRoundToFormat        = 1 << 6,       // Disable rounding underlying value to match precision of the display format string (e.g. %.3f values are rounded to those 3 digits)
    ImGuiSliderFlags_NoInput                = 1 << 7,       // Disable CTRL+Click or Enter key allowing to input text directly into the widget
    ImGuiSliderFlags_InvalidMask_           = 0x7000000F    // [Internal] We treat using those bits as being potentially a 'float power' argument from the previous API that has got miscast to this enum, and will trigger an assert if needed.

    // Obsolete names (will be removed)
#ifndef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
    , ImGuiSliderFlags_ClampOnInput = ImGuiSliderFlags_AlwaysClamp // [renamed in 1.79]
#endif
};

// Identify a mouse button.
// Those values are guaranteed to be stable and we frequently use 0/1 directly. Named enums provided for convenience.
enum ImGuiMouseButton_
{
    ImGuiMouseButton_Left = 0,
    ImGuiMouseButton_Right = 1,
    ImGuiMouseButton_Middle = 2,
    ImGuiMouseButton_COUNT = 5
};

// Enumeration for GetMouseCursor()
// User code may request backend to display given cursor by calling SetMouseCursor(), which is why we have some cursors that are marked unused here
enum ImGuiMouseCursor_
{
    ImGuiMouseCursor_None = -1,
    ImGuiMouseCursor_Arrow = 0,
    ImGuiMouseCursor_TextInput,         // When hovering over InputText, etc.
    ImGuiMouseCursor_ResizeAll,         // (Unused by Dear ImGui functions)
    ImGuiMouseCursor_ResizeNS,          // When hovering over an horizontal border
    ImGuiMouseCursor_ResizeEW,          // When hovering over a vertical border or a column
    ImGuiMouseCursor_ResizeNESW,        // When hovering over the bottom-left corner of a window
    ImGuiMouseCursor_ResizeNWSE,        // When hovering over the bottom-right corner of a window
    ImGuiMouseCursor_Hand,              // (Unused by Dear ImGui functions. Use for e.g. hyperlinks)
    ImGuiMouseCursor_NotAllowed,        // When hovering something with disallowed interaction. Usually a crossed circle.
    ImGuiMouseCursor_COUNT
};

// Enumeration for ImGui::SetWindow***(), SetNextWindow***(), SetNextItem***() functions
// Represent a condition.
// Important: Treat as a regular enum! Do NOT combine multiple values using binary operators! All the functions above treat 0 as a shortcut to ImGuiCond_Always.
enum ImGuiCond_
{
    ImGuiCond_None          = 0,        // No condition (always set the variable), same as _Always
    ImGuiCond_Always        = 1 << 0,   // No condition (always set the variable)
    ImGuiCond_Once          = 1 << 1,   // Set the variable once per runtime session (only the first call will succeed)
    ImGuiCond_FirstUseEver  = 1 << 2,   // Set the variable if the object/window has no persistently saved data (no entry in .ini file)
    ImGuiCond_Appearing     = 1 << 3    // Set the variable if the object/window is appearing after being hidden/inactive (or the first time)
};
// Scalar data types
typedef unsigned int        ImGuiID;
typedef signed char         ImS8;   
typedef unsigned char       ImU8;   
typedef signed short        ImS16;  
typedef unsigned short      ImU16;  
typedef signed int          ImS32;  
typedef unsigned int        ImU32;  
#if defined(_MSC_VER) && !defined(__clang__)
typedef signed   __int64    ImS64;
typedef unsigned __int64    ImU64;
#elif (defined(__clang__) || defined(__GNUC__)) && (__cplusplus < 201100)
#include <stdint.h>
typedef int64_t             ImS64;
typedef uint64_t            ImU64;
#else
typedef signed   long long  ImS64;
typedef unsigned long long  ImU64;
#endif

// Character types
typedef unsigned short ImWchar16;
typedef unsigned int ImWchar32;  
typedef ImWchar16 ImWchar;

struct ImVec2
{
    float                                   x, y;
    ImVec2()                                { x = y = 0.0f; }
    ImVec2(float _x, float _y)              { x = _x; y = _y; }
    float  operator[] (size_t idx) const    { return (&x)[idx]; }
    float& operator[] (size_t idx)          { return (&x)[idx]; }
};
struct ImVec4
{
    float                                           x, y, z, w;
    ImVec4()                                        { x = y = z = w = 0.0f; }
    ImVec4(float _x, float _y, float _z, float _w)  { x = _x; y = _y; z = _z; w = _w; }
};
struct ImGuiInputTextCallbackData
{
    ImGuiInputTextFlags EventFlag, Flags;
    void*               UserData;
    ImWchar             EventChar;
    ImGuiKey            EventKey;
    char*               Buf;
    int                 BufTextLen, BufSize;
    bool                BufDirty;
    int                 CursorPos, SelectionStart, SelectionEnd;
                        ImGuiInputTextCallbackData() { memset(this, 0, sizeof(*this)); }
    inline void         DeleteChars(int pos, int bytes_count)
    {
        char* dst = Buf + pos;
        const char* src = Buf + pos + bytes_count;
        while (char c = *src++) *dst++ = c;
        *dst = '\0';
        if (CursorPos >= pos + bytes_count) CursorPos -= bytes_count;
        else if (CursorPos >= pos) CursorPos = pos;
        SelectionStart = SelectionEnd = CursorPos;
        BufDirty = true;
        BufTextLen -= bytes_count;
    }
    inline void         SelectAll()             { SelectionStart = 0; SelectionEnd = BufTextLen; }
    inline void         ClearSelection()        { SelectionStart = SelectionEnd = BufTextLen; }
    inline bool         HasSelection() const    { return SelectionStart != SelectionEnd; }
};
struct ImGuiSizeCallbackData
{
    void*   UserData;
    ImVec2  Pos;
    ImVec2  CurrentSize;
    ImVec2  DesiredSize;
};
struct ImGuiTableColumnSortSpecs
{
    ImGuiID                     ColumnUserID;
    ImS16                       ColumnIndex;
    ImS16                       SortOrder;
    ImGuiSortDirection          SortDirection : 8;
};
struct ImGuiTableSortSpecs
{
    const ImGuiTableColumnSortSpecs* Specs;
    int                         SpecsCount;
    bool                        SpecsDirty;
};
// Callback and functions types
typedef int     (*ImGuiInputTextCallback)(ImGuiInputTextCallbackData* data);    // Callback function for ImGui::InputText()
typedef void    (*ImGuiSizeCallback)(ImGuiSizeCallbackData* data);              // Callback function for ImGui::SetNextWindowSizeConstraints()
typedef void*   (*ImGuiMemAllocFunc)(size_t sz, void* user_data);               // Function signature for ImGui::SetAllocatorFunctions()
typedef void    (*ImGuiMemFreeFunc)(void* ptr, void* user_data);                // Function signature for ImGui::SetAllocatorFunctions()
#endif

class IImGui
{
public:
    virtual ImFont* GetFont() = 0;
    virtual void AddRenderListener(void* fn) = 0;
    virtual bool RemoveRenderListener(void* fn) = 0;
    virtual void AddMenuRenderListener(void* fn) = 0;
    virtual bool RemoveMenuRenderListener(void* fn) = 0;
    virtual float GetScaledX(float f) = 0;
    virtual float GetScaledY(float f) = 0;
    virtual int GetScreenSizeX() = 0;
    virtual int GetScreenSizeY() = 0;

// ImGui itself
    // Main
    virtual const char* GetVersion() = 0;
    virtual int GetVersionNum() = 0;
    virtual bool Begin(const char* name, bool* p_open = NULL, ImGuiWindowFlags flags = 0) = 0;
    virtual void End() = 0;
    virtual bool BeginChild(const char* str_id, const ImVec2& size = ImVec2(0, 0), bool border = false, ImGuiWindowFlags flags = 0) = 0;
    virtual bool BeginChild(ImGuiID id, const ImVec2& size = ImVec2(0, 0), bool border = false, ImGuiWindowFlags flags = 0) = 0;
    virtual void EndChild() = 0;

    // Combos
    virtual bool BeginCombo(const char* label, const char* preview_value, ImGuiComboFlags flags = 0) = 0;
    virtual void EndCombo() = 0;
    virtual bool Combo(const char* label, int* current_item, const char* const items[], int items_count, int popup_max_height_in_items = -1) = 0;
    virtual bool Combo(const char* label, int* current_item, const char* items_separated_by_zeros, int popup_max_height_in_items = -1) = 0;
    virtual bool Combo(const char* label, int* current_item, bool(*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int popup_max_height_in_items = -1) = 0;

    // Window
    virtual bool IsWindowAppearing() = 0;
    virtual bool IsWindowCollapsed() = 0;
    virtual bool IsWindowFocused(ImGuiFocusedFlags flags = 0) = 0;
    virtual bool IsWindowHovered(ImGuiHoveredFlags flags = 0) = 0;
    virtual ImVec2 GetWindowPos() = 0;
    virtual ImVec2 GetWindowSize() = 0;
    virtual float GetWindowWidth() = 0;
    virtual float GetWindowHeight() = 0;

    // Window manipulation
    virtual void SetNextWindowPos(const ImVec2& pos, ImGuiCond cond = 0, const ImVec2& pivot = ImVec2(0, 0)) = 0;
    virtual void SetNextWindowSize(const ImVec2& size, ImGuiCond cond = 0) = 0;
    virtual void SetNextWindowSizeConstraints(const ImVec2& size_min, const ImVec2& size_max, ImGuiSizeCallback custom_callback = NULL, void* custom_callback_data = NULL) = 0;
    virtual void SetNextWindowContentSize(const ImVec2& size) = 0;
    virtual void SetNextWindowCollapsed(bool collapsed, ImGuiCond cond = 0) = 0;
    virtual void SetNextWindowFocus() = 0;
    virtual void SetNextWindowBgAlpha(float alpha) = 0;
    virtual void SetWindowPos(const ImVec2& pos, ImGuiCond cond = 0) = 0;
    virtual void SetWindowSize(const ImVec2& size, ImGuiCond cond = 0) = 0;
    virtual void SetWindowCollapsed(bool collapsed, ImGuiCond cond = 0) = 0;
    virtual void SetWindowFocus() = 0;
    virtual void SetWindowFontScale(float scale) = 0;
    virtual void SetWindowPos(const char* name, const ImVec2& pos, ImGuiCond cond = 0) = 0;
    virtual void SetWindowSize(const char* name, const ImVec2& size, ImGuiCond cond = 0) = 0;
    virtual void SetWindowCollapsed(const char* name, bool collapsed, ImGuiCond cond = 0) = 0;
    virtual void SetWindowFocus(const char* name) = 0;

    // Cursor / Layout
    virtual void Separator() = 0;
    virtual void SameLine(float offset_from_start_x=0.0f, float spacing=-1.0f) = 0;
    virtual void NewLine() = 0;
    virtual void Spacing() = 0;
    virtual void Dummy(const ImVec2& size) = 0;
    virtual void Indent(float indent_w = 0.0f) = 0;
    virtual void Unindent(float indent_w = 0.0f) = 0;
    virtual void BeginGroup() = 0;
    virtual void EndGroup() = 0;
    virtual ImVec2 GetCursorPos() = 0;
    virtual float GetCursorPosX() = 0;
    virtual float GetCursorPosY() = 0;
    virtual void SetCursorPos(const ImVec2& local_pos) = 0;
    virtual void SetCursorPosX(float local_x) = 0;
    virtual void SetCursorPosY(float local_y) = 0;
    virtual ImVec2 GetCursorStartPos() = 0;
    virtual ImVec2 GetCursorScreenPos() = 0;
    virtual void SetCursorScreenPos(const ImVec2& pos) = 0;
    virtual void AlignTextToFramePadding() = 0;
    virtual float GetTextLineHeight() = 0;
    virtual float GetTextLineHeightWithSpacing() = 0;
    virtual float GetFrameHeight() = 0;
    virtual float GetFrameHeightWithSpacing() = 0;

    // Text
    virtual void TextUnformatted(const char* text, const char* text_end = NULL) = 0;
    virtual void Text(const char* fmt, ...) = 0;
    virtual void TextV(const char* fmt, va_list args) = 0;
    virtual void TextColored(const ImVec4& col, const char* fmt, ...) = 0;
    virtual void TextColoredV(const ImVec4& col, const char* fmt, va_list args) = 0;
    virtual void TextDisabled(const char* fmt, ...) = 0;
    virtual void TextDisabledV(const char* fmt, va_list args) = 0;
    virtual void TextWrapped(const char* fmt, ...) = 0;
    virtual void TextWrappedV(const char* fmt, va_list args) = 0;
    virtual void LabelText(const char* label, const char* fmt, ...) = 0;
    virtual void LabelTextV(const char* label, const char* fmt, va_list args) = 0;
    virtual void BulletText(const char* fmt, ...) = 0;
    virtual void BulletTextV(const char* fmt, va_list args) = 0;

    // Main Widgets
    virtual bool Button(const char* label, const ImVec2& size = ImVec2(0, 0)) = 0;
    virtual bool SmallButton(const char* label) = 0;
    virtual bool InvisibleButton(const char* str_id, const ImVec2& size, ImGuiButtonFlags flags = 0) = 0;
    virtual bool ArrowButton(const char* str_id, ImGuiDir dir) = 0;
    virtual void Image(ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0 = ImVec2(0, 0), const ImVec2& uv1 = ImVec2(1,1), const ImVec4& tint_col = ImVec4(1,1,1,1), const ImVec4& border_col = ImVec4(0,0,0,0)) = 0;
    virtual bool ImageButton(const char* str_id, ImTextureID user_texture_id, const ImVec2& size, const ImVec2& uv0 = ImVec2(0, 0), const ImVec2& uv1 = ImVec2(1, 1), const ImVec4& bg_col = ImVec4(0, 0, 0, 0), const ImVec4& tint_col = ImVec4(1, 1, 1, 1)) = 0;
    virtual bool Checkbox(const char* label, bool* v) = 0;
    virtual bool CheckboxFlags(const char* label, int* flags, int flags_value) = 0;
    virtual bool CheckboxFlags(const char* label, unsigned int* flags, unsigned int flags_value) = 0;
    virtual bool RadioButton(const char* label, bool active) = 0;
    virtual bool RadioButton(const char* label, int* v, int v_button) = 0;
    virtual void ProgressBar(float fraction, const ImVec2& size_arg = ImVec2(-FLT_MIN, 0), const char* overlay = NULL) = 0;
    virtual void Bullet() = 0;

    // Drag Slider
    virtual bool DragFloat(const char* label, float* v, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragFloat2(const char* label, float v[2], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragFloat3(const char* label, float v[3], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragFloat4(const char* label, float v[4], float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragFloatRange2(const char* label, float* v_current_min, float* v_current_max, float v_speed = 1.0f, float v_min = 0.0f, float v_max = 0.0f, const char* format = "%.3f", const char* format_max = NULL, ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragInt(const char* label, int* v, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragInt2(const char* label, int v[2], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragInt3(const char* label, int v[3], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragInt4(const char* label, int v[4], float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragIntRange2(const char* label, int* v_current_min, int* v_current_max, float v_speed = 1.0f, int v_min = 0, int v_max = 0, const char* format = "%d", const char* format_max = NULL, ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragScalar(const char* label, ImGuiDataType data_type, void* p_data, float v_speed = 1.0f, const void* p_min = NULL, const void* p_max = NULL, const char* format = NULL, ImGuiSliderFlags flags = 0) = 0;
    virtual bool DragScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, float v_speed = 1.0f, const void* p_min = NULL, const void* p_max = NULL, const char* format = NULL, ImGuiSliderFlags flags = 0) = 0;

    // Regular Slider
    virtual bool SliderFloat(const char* label, float* v, float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0) = 0;
    virtual bool SliderFloat2(const char* label, float v[2], float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0) = 0;
    virtual bool SliderFloat3(const char* label, float v[3], float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0) = 0;
    virtual bool SliderFloat4(const char* label, float v[4], float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0) = 0;
    virtual bool SliderAngle(const char* label, float* v_rad, float v_degrees_min = -360.0f, float v_degrees_max = +360.0f, const char* format = "%.0f deg", ImGuiSliderFlags flags = 0) = 0;
    virtual bool SliderInt(const char* label, int* v, int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0) = 0;
    virtual bool SliderInt2(const char* label, int v[2], int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0) = 0;
    virtual bool SliderInt3(const char* label, int v[3], int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0) = 0;
    virtual bool SliderInt4(const char* label, int v[4], int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0) = 0;
    virtual bool SliderScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format = NULL, ImGuiSliderFlags flags = 0) = 0;
    virtual bool SliderScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_min, const void* p_max, const char* format = NULL, ImGuiSliderFlags flags = 0) = 0;
    virtual bool VSliderFloat(const char* label, const ImVec2& size, float* v, float v_min, float v_max, const char* format = "%.3f", ImGuiSliderFlags flags = 0) = 0;
    virtual bool VSliderInt(const char* label, const ImVec2& size, int* v, int v_min, int v_max, const char* format = "%d", ImGuiSliderFlags flags = 0) = 0;
    virtual bool VSliderScalar(const char* label, const ImVec2& size, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format = NULL, ImGuiSliderFlags flags = 0) = 0;

    // Input (keyboard)
    virtual bool InputText(const char* label, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL) = 0;
    virtual bool InputTextMultiline(const char* label, char* buf, size_t buf_size, const ImVec2& size = ImVec2(0, 0), ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL) = 0;
    virtual bool InputTextWithHint(const char* label, const char* hint, char* buf, size_t buf_size, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL) = 0;
    virtual bool InputFloat(const char* label, float* v, float step = 0.0f, float step_fast = 0.0f, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) = 0;
    virtual bool InputFloat2(const char* label, float v[2], const char* format = "%.3f", ImGuiInputTextFlags flags = 0) = 0;
    virtual bool InputFloat3(const char* label, float v[3], const char* format = "%.3f", ImGuiInputTextFlags flags = 0) = 0;
    virtual bool InputFloat4(const char* label, float v[4], const char* format = "%.3f", ImGuiInputTextFlags flags = 0) = 0;
    virtual bool InputInt(const char* label, int* v, int step = 1, int step_fast = 100, ImGuiInputTextFlags flags = 0) = 0;
    virtual bool InputInt2(const char* label, int v[2], ImGuiInputTextFlags flags = 0) = 0;
    virtual bool InputInt3(const char* label, int v[3], ImGuiInputTextFlags flags = 0) = 0;
    virtual bool InputInt4(const char* label, int v[4], ImGuiInputTextFlags flags = 0) = 0;
    virtual bool InputDouble(const char* label, double* v, double step = 0.0, double step_fast = 0.0, const char* format = "%.6f", ImGuiInputTextFlags flags = 0) = 0;
    virtual bool InputScalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_step = NULL, const void* p_step_fast = NULL, const char* format = NULL, ImGuiInputTextFlags flags = 0) = 0;
    virtual bool InputScalarN(const char* label, ImGuiDataType data_type, void* p_data, int components, const void* p_step = NULL, const void* p_step_fast = NULL, const char* format = NULL, ImGuiInputTextFlags flags = 0) = 0;

    // Color Picker
    virtual bool ColorEdit3(const char* label, float col[3], ImGuiColorEditFlags flags = 0) = 0;
    virtual bool ColorEdit4(const char* label, float col[4], ImGuiColorEditFlags flags = 0) = 0;
    virtual bool ColorPicker3(const char* label, float col[3], ImGuiColorEditFlags flags = 0) = 0;
    virtual bool ColorPicker4(const char* label, float col[4], ImGuiColorEditFlags flags = 0, const float* ref_col = NULL) = 0;
    virtual bool ColorButton(const char* desc_id, const ImVec4& col, ImGuiColorEditFlags flags = 0, ImVec2 size = ImVec2(0, 0)) = 0;
    virtual void SetColorEditOptions(ImGuiColorEditFlags flags) = 0;

    // Trees
    virtual bool TreeNode(const char* label) = 0;
    virtual bool TreeNode(const char* str_id, const char* fmt, ...) = 0;
    virtual bool TreeNode(const void* ptr_id, const char* fmt, ...) = 0;
    virtual bool TreeNodeV(const char* str_id, const char* fmt, va_list args) = 0;
    virtual bool TreeNodeV(const void* ptr_id, const char* fmt, va_list args) = 0;
    virtual bool TreeNodeEx(const char* label, ImGuiTreeNodeFlags flags = 0) = 0;
    virtual bool TreeNodeEx(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, ...) = 0;
    virtual bool TreeNodeEx(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, ...) = 0;
    virtual bool TreeNodeExV(const char* str_id, ImGuiTreeNodeFlags flags, const char* fmt, va_list args) = 0;
    virtual bool TreeNodeExV(const void* ptr_id, ImGuiTreeNodeFlags flags, const char* fmt, va_list args) = 0;
    virtual void TreePush(const char* str_id) = 0;
    virtual void TreePush(const void* ptr_id = NULL) = 0;
    virtual void TreePop() = 0;
    virtual float GetTreeNodeToLabelSpacing() = 0;
    virtual bool CollapsingHeader(const char* label, ImGuiTreeNodeFlags flags = 0) = 0;
    virtual bool CollapsingHeader(const char* label, bool* p_visible, ImGuiTreeNodeFlags flags = 0) = 0;
    virtual void SetNextItemOpen(bool is_open, ImGuiCond cond = 0) = 0;

    // Selectables
    virtual bool Selectable(const char* label, bool selected = false, ImGuiSelectableFlags flags = 0, const ImVec2& size = ImVec2(0, 0)) = 0;
    virtual bool Selectable(const char* label, bool* p_selected, ImGuiSelectableFlags flags = 0, const ImVec2& size = ImVec2(0, 0)) = 0;

    // List Boxes
    virtual bool BeginListBox(const char* label, const ImVec2& size = ImVec2(0, 0)) = 0;
    virtual void EndListBox() = 0;
    virtual bool ListBox(const char* label, int* current_item, const char* const items[], int items_count, int height_in_items = -1) = 0;
    virtual bool ListBox(const char* label, int* current_item, bool (*items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int height_in_items = -1) = 0;

    // Data Plots
    virtual void PlotLines(const char* label, const float* values, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0, 0), int stride = sizeof(float)) = 0;
    virtual void PlotLines(const char* label, float(*values_getter)(void* data, int idx), void* data, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0, 0)) = 0;
    virtual void PlotHistogram(const char* label, const float* values, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0, 0), int stride = sizeof(float)) = 0;
    virtual void PlotHistogram(const char* label, float(*values_getter)(void* data, int idx), void* data, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0, 0)) = 0;

    // Value helpers
    virtual void Value(const char* prefix, bool b) = 0;
    virtual void Value(const char* prefix, int v) = 0;
    virtual void Value(const char* prefix, unsigned int v) = 0;
    virtual void Value(const char* prefix, float v, const char* float_format = NULL) = 0;

    // Menus
    virtual bool BeginMenuBar() = 0;
    virtual void EndMenuBar() = 0;
    virtual bool BeginMainMenuBar() = 0;
    virtual void EndMainMenuBar() = 0;
    virtual bool BeginMenu(const char* label, bool enabled = true) = 0;
    virtual void EndMenu() = 0;
    virtual bool MenuItem(const char* label, const char* shortcut = NULL, bool selected = false, bool enabled = true) = 0;
    virtual bool MenuItem(const char* label, const char* shortcut, bool* p_selected, bool enabled = true) = 0;

    // Tooltips
    virtual void BeginTooltip() = 0;
    virtual void EndTooltip() = 0;
    virtual void SetTooltip(const char* fmt, ...) = 0;
    virtual void SetTooltipV(const char* fmt, va_list args) = 0;

    // Popups
    virtual bool BeginPopup(const char* str_id, ImGuiWindowFlags flags = 0) = 0;
    virtual bool BeginPopupModal(const char* name, bool* p_open = NULL, ImGuiWindowFlags flags = 0) = 0;
    virtual void EndPopup() = 0;
    virtual void OpenPopup(const char* str_id, ImGuiPopupFlags popup_flags = 0) = 0;
    virtual void OpenPopup(ImGuiID id, ImGuiPopupFlags popup_flags = 0) = 0;
    virtual void OpenPopupOnItemClick(const char* str_id = NULL, ImGuiPopupFlags popup_flags = 1) = 0;
    virtual void CloseCurrentPopup() = 0;        
    virtual bool BeginPopupContextItem(const char* str_id = NULL, ImGuiPopupFlags popup_flags = 1) = 0;
    virtual bool BeginPopupContextWindow(const char* str_id = NULL, ImGuiPopupFlags popup_flags = 1) = 0;
    virtual bool BeginPopupContextVoid(const char* str_id = NULL, ImGuiPopupFlags popup_flags = 1) = 0;
    virtual bool IsPopupOpen(const char* str_id, ImGuiPopupFlags flags = 0) = 0;

    // Tables
    virtual bool BeginTable(const char* str_id, int column, ImGuiTableFlags flags = 0, const ImVec2& outer_size = ImVec2(0.0f, 0.0f), float inner_width = 0.0f) = 0;
    virtual void EndTable() = 0;
    virtual void TableNextRow(ImGuiTableRowFlags row_flags = 0, float min_row_height = 0.0f) = 0;
    virtual bool TableNextColumn() = 0;
    virtual bool TableSetColumnIndex(int column_n) = 0;
    virtual void TableSetupColumn(const char* label, ImGuiTableColumnFlags flags = 0, float init_width_or_weight = 0.0f, ImGuiID user_id = 0) = 0;
    virtual void TableSetupScrollFreeze(int cols, int rows) = 0;
    virtual void TableHeadersRow() = 0;
    virtual void TableHeader(const char* label) = 0;
    virtual ImGuiTableSortSpecs* TableGetSortSpecs() = 0;
    virtual int TableGetColumnCount() = 0;
    virtual int TableGetColumnIndex() = 0;
    virtual int TableGetRowIndex() = 0;
    virtual const char* TableGetColumnName(int column_n = -1) = 0;
    virtual ImGuiTableColumnFlags TableGetColumnFlags(int column_n = -1) = 0;
    virtual void TableSetColumnEnabled(int column_n, bool v) = 0;
    virtual void TableSetBgColor(ImGuiTableBgTarget target, ImU32 color, int column_n = -1) = 0;
    virtual void Columns(int count = 1, const char* id = NULL, bool border = true) = 0;
    virtual void NextColumn() = 0;
    virtual int  GetColumnIndex() = 0;
    virtual float GetColumnWidth(int column_index = -1) = 0;
    virtual void SetColumnWidth(int column_index, float width) = 0;
    virtual float GetColumnOffset(int column_index = -1) = 0;
    virtual void SetColumnOffset(int column_index, float offset_x) = 0;
    virtual int  GetColumnsCount() = 0;

    // Tab bars
    virtual bool BeginTabBar(const char* str_id, ImGuiTabBarFlags flags = 0) = 0;
    virtual void EndTabBar() = 0;
    virtual bool BeginTabItem(const char* label, bool* p_open = NULL, ImGuiTabItemFlags flags = 0) = 0;
    virtual void EndTabItem() = 0;
    virtual bool TabItemButton(const char* label, ImGuiTabItemFlags flags = 0) = 0;
    virtual void SetTabItemClosed(const char* tab_or_docked_window_label) = 0;

    // Focus
    virtual void SetItemDefaultFocus() = 0;
    virtual void SetKeyboardFocusHere(int offset = 0) = 0;

    // Widgets/Items utils
    virtual bool IsItemHovered(ImGuiHoveredFlags flags = 0) = 0;
    virtual bool IsItemActive() = 0;
    virtual bool IsItemFocused() = 0;
    virtual bool IsItemClicked(ImGuiMouseButton mouse_button = 0) = 0;
    virtual bool IsItemVisible() = 0;
    virtual bool IsItemEdited() = 0;
    virtual bool IsItemActivated() = 0;
    virtual bool IsItemDeactivated() = 0;
    virtual bool IsItemDeactivatedAfterEdit() = 0;
    virtual bool IsItemToggledOpen() = 0;
    virtual bool IsAnyItemHovered() = 0;
    virtual bool IsAnyItemActive() = 0;
    virtual bool IsAnyItemFocused() = 0;
    virtual ImVec2 GetItemRectMin() = 0;
    virtual ImVec2 GetItemRectMax() = 0;
    virtual ImVec2 GetItemRectSize() = 0;
    virtual void SetItemAllowOverlap() = 0;

    // Misc utils
    virtual bool IsRectVisible(const ImVec2& size) = 0;
    virtual bool IsRectVisible(const ImVec2& rect_min, const ImVec2& rect_max) = 0;
    virtual double GetTime() = 0;
    virtual int GetFrameCount() = 0;
    virtual const char* GetStyleColorName(ImGuiCol idx) = 0;
    virtual bool BeginChildFrame(ImGuiID id, const ImVec2& size, ImGuiWindowFlags flags = 0) = 0;
    virtual void EndChildFrame() = 0;
    virtual ImVec2 CalcTextSize(const char* text, const char* text_end = NULL, bool hide_text_after_double_hash = false, float wrap_width = -1.0f) = 0;
    virtual ImVec4 ColorConvertU32ToFloat4(ImU32 in) = 0;
    virtual ImU32 ColorConvertFloat4ToU32(const ImVec4& in) = 0;
    virtual void ColorConvertRGBtoHSV(float r, float g, float b, float& out_h, float& out_s, float& out_v) = 0;
    virtual void ColorConvertHSVtoRGB(float h, float s, float v, float& out_r, float& out_g, float& out_b) = 0;

    // Mouse itils
    virtual bool IsMouseDown(ImGuiMouseButton button) = 0;
    virtual bool IsMouseClicked(ImGuiMouseButton button, bool repeat = false) = 0;
    virtual bool IsMouseReleased(ImGuiMouseButton button) = 0;
    virtual bool IsMouseDoubleClicked(ImGuiMouseButton button) = 0;
    virtual int GetMouseClickedCount(ImGuiMouseButton button) = 0;
    virtual bool IsMouseHoveringRect(const ImVec2& r_min, const ImVec2& r_max, bool clip = true) = 0;
    virtual bool IsMousePosValid(const ImVec2* mouse_pos = NULL) = 0;
    virtual bool IsAnyMouseDown() = 0;
    virtual ImVec2 GetMousePos() = 0;
    virtual ImVec2 GetMousePosOnOpeningCurrentPopup() = 0;
    virtual bool IsMouseDragging(ImGuiMouseButton button, float lock_threshold = -1.0f) = 0;
    virtual ImVec2 GetMouseDragDelta(ImGuiMouseButton button = 0, float lock_threshold = -1.0f) = 0;
};