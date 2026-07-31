#ifndef TCC_COMPAT_H
#define TCC_COMPAT_H

// tcc winapi 补充定义：tcc 自带 winapi 精简，部分类型/常量/宏缺失
// 本文件由 Makefile 用 -include 强制包含到每个编译单元前

// ── 解决 tcc parser 不支持 __stdcall 函数指针 typedef 语法 ──
// tcc 0.9.28 parser 无法解析 typedef void (__stdcall *FPTR)(...)
// 在 x86_64 上 __stdcall 是无意义的（只有一个调用约定），可安全置空
// 在 Linux/Mac 上 __stdcall 本就不使用，置空无副作用
#if defined(__x86_64__) || defined(__amd64__) || defined(_M_X64) || defined(__LP64__) || !defined(_WIN32)
#undef __stdcall
#define __stdcall
#endif

// ── MinGW _mingw.h 中的类型别名（tcc 无 _mingw.h） ──
#ifndef __LONG32
#define __LONG32 long
#endif

// ── winuser.h 缺失的 MAPVK_* 常量 ──
#ifndef MAPVK_VK_TO_VSC
#define MAPVK_VK_TO_VSC 0
#endif
#ifndef MAPVK_VSC_TO_VK
#define MAPVK_VSC_TO_VK 1
#endif
#ifndef MAPVK_VK_TO_CHAR
#define MAPVK_VK_TO_CHAR 2
#endif
#ifndef MAPVK_VSC_TO_VK_EX
#define MAPVK_VSC_TO_VK_EX 3
#endif

// ── winuser.h 缺失的 DPI 相关 Windows 消息常量 ──
#ifndef WM_DPICHANGED
#define WM_DPICHANGED 0x02E3
#endif
#ifndef WM_GETDPISCALEDSIZE
#define WM_GETDPISCALEDSIZE 0x02E4
#endif

// ── winnls.h 缺失的代码页常量 ──
// raylib rcore_desktop_win32.c / miniaudio / RGFW / glfw 都用 CP_UTF8 调 MultiByteToWideChar
#ifndef CP_UTF8
#define CP_UTF8 65001
#endif

// HDROP 由 MinGW shellapi.h 提供，无需在此定义

// ── 跳过 MinGW intrin-impl.h 中的 GCC inline assembly ──
// MinGW 默认 #define __has_builtin(x) 0，导致 inline asm 被启用
// tcc 不支持这些 GCC inline asm，故定义为 1 跳过所有 inline 实现
#ifndef __has_builtin
#define __has_builtin(x) 1
#endif

// ── 禁用 miniaudio SSE2/AVX intrinsics ──
// tcc 不支持 SSE/AVX intrinsics，需禁用以避免编译错误
#define MA_NO_SSE2
#define MA_NO_AVX
#define MA_NO_AVX2

// ── winuser.h HWND_* 常量被错误地放在 #if !defined(NOGDI) 块内 ──
// 当定义 NOGDI（避免 raylib Rectangle 与 Windows GDI Rectangle 冲突）时，
// HWND_TOP/HWND_BOTTOM/HWND_TOPMOST/HWND_NOTOPMOST 会被排除
#ifndef HWND_TOP
#define HWND_TOP       ((HWND)0)
#endif
#ifndef HWND_BOTTOM
#define HWND_BOTTOM    ((HWND)1)
#endif
#ifndef HWND_TOPMOST
#define HWND_TOPMOST   ((HWND)-1)
#endif
#ifndef HWND_NOTOPMOST
#define HWND_NOTOPMOST ((HWND)-2)
#endif
// ── winuser.h SWP_* 常量同样被错误地放在 #if !defined(NOGDI) 块内 ──
// SetWindowPos 使用的标志位，定义 NOGDI 时一并被排除
#ifndef SWP_NOSIZE
#define SWP_NOSIZE        0x0001
#endif
#ifndef SWP_NOMOVE
#define SWP_NOMOVE        0x0002
#endif
#ifndef SWP_NOZORDER
#define SWP_NOZORDER      0x0004
#endif
#ifndef SWP_NOREDRAW
#define SWP_NOREDRAW      0x0008
#endif
#ifndef SWP_NOACTIVATE
#define SWP_NOACTIVATE    0x0010
#endif
#ifndef SWP_FRAMECHANGED
#define SWP_FRAMECHANGED  0x0020
#endif
#ifndef SWP_SHOWWINDOW
#define SWP_SHOWWINDOW    0x0040
#endif
#ifndef SWP_HIDEWINDOW
#define SWP_HIDEWINDOW    0x0080
#endif
#ifndef SWP_NOCOPYBITS
#define SWP_NOCOPYBITS    0x0100
#endif
#ifndef SWP_NOOWNERZORDER
#define SWP_NOOWNERZORDER 0x0200
#endif
#ifndef SWP_NOSENDCHANGING
#define SWP_NOSENDCHANGING 0x0400
#endif
#ifndef SWP_DRAWFRAME
#define SWP_DRAWFRAME     SWP_FRAMECHANGED
#endif
#ifndef SWP_NOREPOSITION
#define SWP_NOREPOSITION  SWP_NOOWNERZORDER
#endif
#ifndef SWP_DEFERERASE
#define SWP_DEFERERASE    0x2000
#endif
#ifndef SWP_ASYNCWINDOWPOS
#define SWP_ASYNCWINDOWPOS 0x4000
#endif
// ── winuser.h IDC_* 系统光标常量同样被错误地放在 #if !defined(NOGDI) 块内 ──
// raylib 的 rcore_desktop_win32.c 用 LoadCursor(IDC_ARROW) 等加载系统光标
#ifndef IDC_ARROW
#define IDC_ARROW       MAKEINTRESOURCE(32512)
#endif
#ifndef IDC_IBEAM
#define IDC_IBEAM       MAKEINTRESOURCE(32513)
#endif
#ifndef IDC_WAIT
#define IDC_WAIT        MAKEINTRESOURCE(32514)
#endif
#ifndef IDC_CROSS
#define IDC_CROSS       MAKEINTRESOURCE(32515)
#endif
#ifndef IDC_UPARROW
#define IDC_UPARROW     MAKEINTRESOURCE(32516)
#endif
#ifndef IDC_SIZE
#define IDC_SIZE        MAKEINTRESOURCE(32640)
#endif
#ifndef IDC_ICON
#define IDC_ICON        MAKEINTRESOURCE(32641)
#endif
#ifndef IDC_SIZENWSE
#define IDC_SIZENWSE    MAKEINTRESOURCE(32642)
#endif
#ifndef IDC_SIZENESW
#define IDC_SIZENESW    MAKEINTRESOURCE(32643)
#endif
#ifndef IDC_SIZEWE
#define IDC_SIZEWE      MAKEINTRESOURCE(32644)
#endif
#ifndef IDC_SIZENS
#define IDC_SIZENS      MAKEINTRESOURCE(32645)
#endif
#ifndef IDC_SIZEALL
#define IDC_SIZEALL     MAKEINTRESOURCE(32646)
#endif
#ifndef IDC_NO
#define IDC_NO          MAKEINTRESOURCE(32648)
#endif
#ifndef IDC_HAND
#define IDC_HAND        MAKEINTRESOURCE(32649)
#endif
#ifndef IDC_APPSTARTING
#define IDC_APPSTARTING MAKEINTRESOURCE(32650)
#endif
#ifndef IDC_HELP
#define IDC_HELP        MAKEINTRESOURCE(32651)
#endif

#endif // TCC_COMPAT_H
