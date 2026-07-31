#ifndef RAYLIB_COMPAT_H
#define RAYLIB_COMPAT_H

// 1. 先 include raylib.h（此时 windows.h 未 include，宏未定义）
//    raylib 的 Rectangle struct / CloseWindow / ShowCursor 等声明保持原名
#include "raylib.h"

// 2. 重命名 Windows 的 GDI/user32 函数（在 windows.h 之前）
//    这样 windows.h 的 CloseWindow(HWND) → CloseWindowWin32(HWND)，不与 raylib 冲突
//    （与 raylib rcore_desktop_win32.c 第 46-52 行重命名列表一致）
#define CloseWindow CloseWindowWin32
#define Rectangle RectangleWin32
#define ShowCursor ShowCursorWin32
#define DrawTextA DrawTextAWin32
#define DrawTextW DrawTextWin32
#define DrawTextExA DrawTextExAWin32
#define DrawTextExW DrawTextExWin32

// 3. 自己 include windows.h（Windows 的函数被重命名成 *Win32）
//    common.h 之后的 #include <windows.h> 会被 include guard 跳过
#define UNICODE
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// 4. 恢复符号名（让后续代码用 Rectangle 调用 raylib 的 struct）
#undef CloseWindow
#undef Rectangle
#undef ShowCursor
#undef DrawTextA
#undef DrawTextW
#undef DrawTextExA
#undef DrawTextExW
// DrawText/DrawTextEx/LoadImage 是 windows.h 的宏（UNICODE 下展开为 *W 后缀）
#ifdef DrawText
#undef DrawText
#endif
#ifdef DrawTextEx
#undef DrawTextEx
#endif
#ifdef LoadImage
#undef LoadImage
#endif

#endif // RAYLIB_COMPAT_H