// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

/// @file

#ifndef BAREMETAL_LIBC_STRING_H
#define BAREMETAL_LIBC_STRING_H

#include <baremetal/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Copies a portion of memory
/// from one location to another.
/// @param dst Pointer to the location
/// to copy memory to.
/// @param src Pointer to the location
/// to copy memory from.
/// @param count Number of bytes to copy.
/// @returns Pointer to @p dst.
void *memcpy(void *dst,
             const void *src,
             size_t count);

/// @brief Compares two null-terminated
/// byte strings in lexical order.
/// @param a A null-terminated string.
/// @param b A null-terminated string.
/// @returns A negative one if @p a is
/// before @p b. A positive one if @p a
/// is after @p b. Zero if the contents
/// of @p a and @p b are the same.
int strcmp(const char *a,
           const char *b);

/// @brief Determines the length of a string.
/// @param str A null-terminated string.
/// @returns The length of the string, not
/// including the null terminator.
size_t strlen(const char *str);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // BAREMETAL_LIBC_STRING_H
