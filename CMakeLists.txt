cmake_minimum_required(VERSION 3.0.2)

project("BareMetal libc")

if (CMAKE_C_COMPILER_IS_GNUCC)
	set (BAREMETAL_C_FLAGS "${BAREMETAL_C_FLAGS} -Wall -Wextra -Werror -Wfatal-errors")
	set (BAREMETAL_C_FLAGS "${BAREMETAL_C_FLAGS} -nostdlib -nostdinc")
endif (CMAKE_C_COMPILER_IS_GNUCC)

find_package(Doxygen)
if (DOXYGEN_FOUND AND DOXYGEN_DOT_FOUND)
	add_custom_target("doc" ALL
		COMMAND ${DOXYGEN_EXECUTABLE}
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
		COMMENT "Generating Doxygen API documentation")
endif (DOXYGEN_FOUND AND DOXYGEN_DOT_FOUND)

macro(ADD_HEADER_AND_SOURCE VAR HEADER SOURCE)
	list (APPEND ${VAR}
		"${PROJECT_SOURCE_DIR}/include/${HEADER}"
		"${PROJECT_SOURCE_DIR}/src/${SOURCE}")
endmacro(ADD_HEADER_AND_SOURCE VAR HEADER SOURCE)

unset (SOURCES)

add_header_and_source(SOURCES
	"baremetal/baremetal.h"
	"baremetal.c")

add_header_and_source(SOURCES
	"string.h"
	"string.c")

add_library("baremetal" ${SOURCES})

if (CMAKE_COMPILER_IS_GNUCC)
	target_compile_options("baremetal" PRIVATE -Wall -Wextra -Werror -Wfatal-errors)
endif (CMAKE_COMPILER_IS_GNUCC)

target_include_directories("baremetal" PRIVATE "include")
target_include_directories("baremetal" INTERFACE "${CMAKE_INSTALL_PREFIX}/include")
