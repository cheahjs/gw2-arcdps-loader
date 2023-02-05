#pragma once

#include <imgui.h>
#include "../dep/loader-core/include/gw2al_api.h"
#include "../dep/lib_imgui/gw2al_lib_imgui.h"

#include "Gui.h"

#define WIN32_LEAN_AND_MEAN
#include <Main.h>
#include <windows.h>

struct addon_instance
{
	gw2al_core_vtable* api;
	Main main;
	lib_imgui<Gui> gui;
};

addon_instance& gAddon();
