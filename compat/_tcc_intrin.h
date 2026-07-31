/*
 * _tcc_intrin.h - SSE intrinsics stubs for TCC
 *
 * TCC does not support SSE intrinsics. This file provides empty
 * stubs so that code using #include <emmintrin.h> or <x86intrin.h>
 * can compile without errors when built with TCC.
 *
 * For TCC builds, include this file via -include or add to include path.
 * This file is NOT in the standard compat include path to avoid
 * shadowing system headers on MSVC / GCC / Clang.
 */

#ifndef _TCC_INTRIN_H
#define _TCC_INTRIN_H

/* Placeholder for future TCC-specific intrinsics stubs */

#endif /* _TCC_INTRIN_H */
