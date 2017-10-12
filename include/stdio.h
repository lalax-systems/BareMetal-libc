// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

/// @file stdio.h
/// @brief Standard input and output functions
/// and definitions.

/// @defgroup baremetal-stdio Standard Input and Output
/// @brief Functions and definitions related to standard
/// input and output.

#ifndef BAREMETAL_LIBC_STDIO_H
#define BAREMETAL_LIBC_STDIO_H

/// @brief Move the file position relative
/// to the beginning of the file.
/// @ingroup baremetal-stdio
#define SEEK_SET 0

/// @brief Move the file position relative
/// to the current position of the file.
/// @ingroup baremetal-stdio
#define SEEK_CUR 1

/// @brief Move the file position relative
/// to the end of the file.
/// @ingroup baremetal-stdio
#define SEEK_END 2

#endif // BAREMETAL_LIBC_STDIO_H
