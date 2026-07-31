#ifndef _SHELLSCALINGAPI_H_TCC_STUB
#define _SHELLSCALINGAPI_H_TCC_STUB

// shellscalingapi.h stub for tcc (only provides types/functions used by raylib)
#include <windows.h>

// ── PROCESS_DPI_AWARENESS (shcore.dll) ──
// MSVC + Windows SDK already provide these types via <windows.h>;
// they are only needed for TCC which has a minimal <windows.h>.
#if !defined(_MSC_VER)
typedef enum PROCESS_DPI_AWARENESS {
    PROCESS_DPI_UNAWARE = 0,
    PROCESS_SYSTEM_DPI_AWARE = 1,
    PROCESS_PER_MONITOR_DPI_AWARE = 2
} PROCESS_DPI_AWARENESS;

HRESULT WINAPI SetProcessDpiAwareness(PROCESS_DPI_AWARENESS value);

// ── DPI_AWARENESS_CONTEXT (user32.dll, Windows 10 1703+) ──
DECLARE_HANDLE(DPI_AWARENESS_CONTEXT);

#define DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2 ((DPI_AWARENESS_CONTEXT)-2)

BOOL WINAPI SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT value);
#endif

#endif
