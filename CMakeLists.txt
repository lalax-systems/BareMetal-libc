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

add_executable("generate-limits" "src/generate-limits.c")

add_custom_command(OUTPUT "${PROJECT_SOURCE_DIR}/include/limits.h"
	COMMAND $<TARGET_FILE:generate-limits> --output "${PROJECT_SOURCE_DIR}/include/limits.h"
	COMMENT "Generating limits.h")

macro(ADD_HEADER VAR HEADER)
	list (APPEND ${VAR} "${PROJECT_SOURCE_DIR}/include/${HEADER}")
endmacro(ADD_HEADER VAR_HEADER)

macro(ADD_SOURCE VAR SOURCE)
	list (APPEND ${VAR} "${PROJECT_SOURCE_DIR}/src/${SOURCE}")
endmacro(ADD_SOURCE VAR SOURCE)

macro(ADD_HEADER_AND_SOURCE VAR HEADER SOURCE)
	add_header(${VAR} ${HEADER})
	add_source(${VAR} ${SOURCE})
endmacro(ADD_HEADER_AND_SOURCE VAR HEADER SOURCE)

unset (SOURCES)

add_header(SOURCES "baremetal/types.h")
add_header(SOURCES "limits.h")

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
