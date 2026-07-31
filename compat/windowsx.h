#ifndef _WINDOWSX_H_TCC_STUB
#define _WINDOWSX_H_TCC_STUB

// windowsx.h stub for tcc (only provides macros used by raylib)
#include <windows.h>

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#endif

#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))
#endif

#endif
