#pragma once
#include <cstdint>
#include <Windows.h>
#include "../dep/imgui/imgui.h"

// `e0` returns `wchar_t*` path to arcdps ini
wchar_t* e0();
// `e3` logs str to `arcdps.log`.
void e3(char* str);
// `e5` writes colour array ptrs to `*out`, where `*out` is an `ImVec4* out[5]`.
void e5(ImVec4** out);
// `e6` returns bit mask of current ui settings.
uint64_t e6();
// `e7` returns modifier virtual key ids in word split.
uint64_t e7();
// `e8` logs str to logger window, extension tab
void e8(char* str);
// `e9` adds ev to arc's event processing
void e9(void* ev, uint32_t sig);
// `addextension2` loads an extension
uint32_t addextension2(HINSTANCE hinst);
// `freeextension2` removes an extension
uint32_t freeextension2(uint32_t sig);