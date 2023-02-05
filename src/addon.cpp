#include "addon.h"

//gw2addon_get_description
//gw2addon_load
//gw2addon_unload


gw2al_addon_dsc gAddonDeps[] = {
	GW2AL_CORE_DEP_ENTRY,
	LIB_IMGUI_DEP_ENTRY,
	{0, 0, 0, 0, 0, 0}
};

gw2al_addon_dsc gAddonDsc = {
	L"arcdps-loader",
	L"addon to load arcdps extensions",
	0,
	0,
	1,
	gAddonDeps
};

addon_instance gInst;

addon_instance& gAddon() { return gInst; }

template <>
inline lib_imgui<Gui>& lib_imgui<Gui>::instance() {
	return gInst.gui;
}


gw2al_addon_dsc* gw2addon_get_description()
{
	return &gAddonDsc;
}

gw2al_api_ret gw2addon_load(gw2al_core_vtable* core_api)
{
	gInst.api = core_api;

	gInst.gui.init(core_api, gAddonDsc.name);

	return GW2AL_OK;
}

gw2al_api_ret gw2addon_unload(int gameExiting)
{
	gInst.gui.deinit();

	return GW2AL_OK;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
                      LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
