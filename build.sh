#!/bin/bash

set -e

if [ "$CC" == "" ]; then
	CC=gcc
fi

if [ "$CC" == "gcc" ]; then
	CFLAGS="-Wall -Wextra -Werror -Wfatal-errors -Iinclude"
fi

if [ "$AR" == "" ]; then
	AR=ar
fi

if [ "$AR" == "ar" ]; then
	ARFLAGS=rcs
fi

function compile {
	echo "CC $1"
	if [ "$CC" == "gcc" ]; then
		$CC $CFLAGS -c $1 -o$2
	fi
}

function generate_limits {
	$CC -Wall -Wextra -Werror -Wfatal-errors src/generate-limits.c -o src/generate-limits
	src/generate-limits --output $1
}

generate_limits include/limits.h

function link_static {
	echo "AR $1"
	if [ "$AR" == "ar" ]; then
		$AR $ARFLAGS $1 ${@:2}
	fi
}

set -u

compile src/string.c src/string.o
compile src/baremetal.c src/baremetal.o
link_static libbaremetal.a src/baremetal.o src/string.o
