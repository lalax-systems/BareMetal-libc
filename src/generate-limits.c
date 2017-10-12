// =======================================================================
// BareMetal Standard C Library -- The standard C library for BareMetal OS
// Copyright (C) 2008-2017 Return Infinity -- see LICENSE
//
// Version 1.0
// =======================================================================

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define WRITE_SFIELD(file, name, value) \
	fprintf(file, "#define %s %lldLL\n\n", name, (long long int) value)

#define WRITE_UFIELD(file, name, value) \
	fprintf(file, "#define %s %lluULL\n\n", name, (unsigned long long int) value)

static int generate_limits(FILE *output) {

	fprintf(output, "//=======================================================\n");
	fprintf(output, "// BareMetal Standard C Library\n");
	fprintf(output, "// Copyright (C) 2008-2017 Return Infinity -- see LICENSE\n");
	fprintf(output, "//\n");
	fprintf(output, "// Version 1.0\n");
	fprintf(output, "//=======================================================\n");
	fprintf(output, "\n");
	fprintf(output, "// This file was automatically generated.\n");
	fprintf(output, "\n");

	fprintf(output, "#ifndef BAREMETAL_LIBC_LIMITS_H\n");
	fprintf(output, "#define BAREMETAL_LIBC_LIMITS_H\n");
	fprintf(output, "\n");

	WRITE_UFIELD(output, "CHAR_BITS", 8);

	WRITE_SFIELD(output, "SCHAR_MIN", -127);
	WRITE_SFIELD(output, "SCHAR_MAX",  127);

	WRITE_UFIELD(output, "UCHAR_MAX", 255);

	WRITE_SFIELD(output, "CHAR_MIN", -127);
	WRITE_SFIELD(output, "CHAR_MAX",  127);

	WRITE_UFIELD(output, "MB_LEN_MAX", 1);

	WRITE_SFIELD(output, "SHRT_MAX", SHRT_MAX);
	WRITE_SFIELD(output, "SHRT_MIN", SHRT_MIN);

	WRITE_UFIELD(output, "USHRT_MAX", USHRT_MAX);

	WRITE_SFIELD(output, "INT_MAX", INT_MAX);
	WRITE_SFIELD(output, "INT_MIN", INT_MIN);

	WRITE_UFIELD(output, "UINT_MAX", UINT_MAX);

	WRITE_SFIELD(output, "LONG_MIN", LONG_MIN);
	WRITE_SFIELD(output, "LONG_MAX", LONG_MAX);

	WRITE_UFIELD(output, "ULONG_MAX", ULONG_MAX);

	WRITE_SFIELD(output, "LLONG_MIN", LLONG_MIN);
	WRITE_SFIELD(output, "LLONG_MAX", LLONG_MAX);

	WRITE_UFIELD(output, "ULLONG_MAX", ULLONG_MAX);

	fprintf(output, "#endif // BAREMETAL_LIBC_LIMITS_H\n");

	return EXIT_SUCCESS;
}

int main(int argc, const char **argv) {

	const char *output_path = NULL;

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--output") == 0) {
			output_path = argv[i + 1];
			i++;
		} else {
			fprintf(stderr, "%s: Unknown option '%s'\n", argv[0], argv[i]);
			return EXIT_FAILURE;
		}
	}

	if (output_path == NULL)
		output_path = "limits.h";

	FILE *output = fopen(output_path, "wb");
	if (output == NULL) {
		fprintf(stderr, "%s: Failed to open '%s': %s\n", argv[0], output_path, strerror(errno));
		return EXIT_FAILURE;
	}

	int err = generate_limits(output);
	if (err != EXIT_SUCCESS) {
		fclose(output);
		return EXIT_FAILURE;
	}

	fclose(output);
	return EXIT_SUCCESS;
}

