// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

/// @file stdlib.h
/// @brief A group of general purpose functions
/// and definitions.

/// @defgroup baremetal-stdlib Stdlib
/// @brief A group of general purpose functions
/// and definitions.

#ifndef BAREMETAL_LIBC_STDLIB_H
#define BAREMETAL_LIBC_STDLIB_H

#include <baremetal/types.h>

/// @brief Used to represent an invalid
/// address.
/// @ingroup baremetal-stdlib
#define NULL ((void *) 0)

/// @brief Returned by main if an error
/// occured within the program.
/// @ingroup baremetal-stdlib
#define EXIT_FAILURE 1

/// @brief Returned by main if a program
/// exited without any errors.
/// @ingroup baremetal-stdlib
#define EXIT_SUCCESS 0

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // BAREMETAL_LIBC_STDLIB_H
