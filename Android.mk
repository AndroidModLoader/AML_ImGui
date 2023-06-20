LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION := .cpp .cc
LOCAL_MODULE    := DearImGui
LOCAL_SRC_FILES := main.cpp mod/logger.cpp iimgui.cpp imgui.cpp imgui_draw.cpp imgui_tables.cpp imgui_widgets.cpp
LOCAL_SRC_FILES += backends/imgui_impl_renderware.cpp RW/RenderWare.cpp  # Renderware part
LOCAL_CFLAGS += -O2 -mfloat-abi=softfp -DNDEBUG -std=c++17
LOCAL_CFLAGS += -DIGNORE_IMGUI_THINGS # Do not define this in your project that uses ImGui
LOCAL_CFLAGS += -DIMGUI_DISABLE_OBSOLETE_FUNCTIONS -DIMGUI_USE_STB_SPRINTF -DDONT_IMPLEMENT_STB
LOCAL_C_INCLUDES += ./. ./stb
LOCAL_LDLIBS += -llog
include $(BUILD_SHARED_LIBRARY)