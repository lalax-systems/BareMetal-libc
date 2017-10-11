cmake_minimum_required(VERSION 3.0.2)

project("BareMetal libc")

add_library("baremetal"
	"include/baremetal/baremetal.h"
	"src/baremetal.c")

if (CMAKE_COMPILER_IS_GNUCC)
	target_compile_options("baremetal" PRIVATE -Wall -Wextra -Werror -Wfatal-errors)
endif (CMAKE_COMPILER_IS_GNUCC)

target_include_directories("baremetal" PRIVATE "include")
target_include_directories("baremetal" INTERFACE "${CMAKE_INSTALL_PREFIX}/include")
