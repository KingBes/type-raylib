#ifndef _STDBOOL_H
#define _STDBOOL_H

#ifndef __cplusplus

/* ISOC99 boolean */

/*
 * clang / gcc C compilers support C99 _Bool natively.
 * MSVC 2019 (v1920) and later also support _Bool as a built-in keyword
 * in C compilation mode. Only older MSVC needs the typedef workaround.
 */
#if defined(_MSC_VER) && !defined(__clang__) && _MSC_VER < 1920
typedef signed char _Bool;
#endif

#define bool	_Bool
#define true	1
#define false	0
#define __bool_true_false_are_defined 1

#endif /* __cplusplus */

#endif /* _STDBOOL_H */
