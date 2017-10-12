// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

/// @file errno.h
/// @brief Contains standard error codes
/// used by the standard library to describe
/// failures.

#ifndef BAREMETAL_LIBC_ERRNO_H
#define BAREMETAL_LIBC_ERRNO_H

/// @brief Error allocating memory.
#define ENOMEM 1

/// @brief No such file or directory.
#define ENOENT 2

/// @brief File or directory already exists.
#define EEXIST 3

/// @brief Invalid argument.
#define EINVAL 4

/// @brief Input or output error.
#define EIO 5

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Used by standard library functions
/// to describe why they failures.
extern int errno;

#ifdef __cplusplus
} // extern "C" {
#endif

#endif // BAREMETAL_LIBC_ERRNO_H
