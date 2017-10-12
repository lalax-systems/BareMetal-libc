// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#ifndef BAREMETAL_LIBC_STDINT_H
#define BAREMETAL_LIBC_STDINT_H

#include <limits.h>

#define INT32_MAX  2147483647L
#define INT32_MIN -2147483648L

#define UINT32_MAX 4294967295ULL

#define INT64_MAX  9223372036854775807LL
#define INT64_MIN -9223372036854775808LL

#define UINT64_MAX 18446744073709551615ULL

#if UINT_MAX == UINT32_MAX
typedef unsigned int uint32_t;
#elif ULONG_MAX == UINT32_MAX
typedef unsigned long int uint32_t;
#endif

#if INT_MAX == INT32_MAX
typedef int int32_t;
#elif LONG_MAX == INT32_MAX
typedef long int int32_t;
#endif

#if ULONG_MAX == UINT64_MAX
typedef unsigned long int uint64_t;
#elif ULLONG_MAX == UINT64_MAX
typedef unsigned long long int uint64_t;
#endif

#if LONG_MAX == INT64_MAX
typedef long int int64_t;
#elif LLONG_MAX == INT64_MAX
typedef long long int int64_t;
#endif

#endif // BAREMETAL_LIBC_STDINT_H
