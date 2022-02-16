# CMakeLists.txt for the Cpp_exercises project
# Notes:
# 	To use a different compiler with CMake, run it as follows:
# 	cmake -D CMAKE_C_COMPILER=/path/to/your/cc -D CMAKE_CXX_COMPILER=/path/to/your/c++ your_project_dir
#
cmake_minimum_required (VERSION 3.1...3.6)

# My own cmake Modules
#	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

# -----------------------------------
# Project name, version & build type
# -----------------------------------
project(CppProjectExample
    VERSION 0.1
    DESCRIPTION "An example project with CMake"
    LANGUAGES CXX)

# Forces Build type release----------------------------
if (NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")


# Disables in-source builds to prevent source tree corruption.
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
       Ex: 
           mkdir build/debug
           cd build/debug
           cmake ..
")
endif()

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
    
    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDE's
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    
    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    find_package(Doxygen)
    if(Doxygen_FOUND AND EXISTS docs)
	    add_subdirectory(docs)
    else()
	    message(STATUS "Doxygen not found, not building docs")
    endif()
endif()

# Accumulator library
# This is header only, so could be replaced with git submodules or FetchContent
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
# find_package(Boost REQUIRED)
find_package(Threads REQUIRED)
# find_package(Catch2 REQUIRED) # Uncomment if Catch2 is installed
set(CMAKE_VERBOSE_MAKEFILE OFF)


# ----------------------------
# General C/C++ build settings
# ----------------------------

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wpedantic -fPIC -ftest-coverage" )
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -Og -g -march=native -fsanitize=address -Woverloaded-virtual")
SET(CMAKE_C_ARCHIVE_FINISH   "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
SET(CMAKE_CXX_ARCHIVE_FINISH "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -fsanitize=address")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    message(STATUS "Unit Tests: Included")
     # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)  # Automatically invokes 
    enable_testing()
    add_subdirectory(tests)
endif()

# ---------------------
# Config File
# ____________________
configure_file(include/build.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/include/build.hpp)

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(main)

# Determine install paths
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")


# ---------------------
# Enable options
# ---------------------

# Output Color
option(FORCE_COLORED_OUTPUT
	   "Always produce ANSI-colored output (GNU/Clang only)." TRUE) 
if(${FORCE_COLORED_OUTPUT})
	if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
		add_compile_options(-fdiagnostics-color=always)
	elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
		add_compile_options(-fcolor-diagnostics)
	endif()
endif()

# Sanitizer
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    option(ENABLE_SANITIZER "Enable sanitizer." TRUE)
endif()
if(${ENABLE_SANITIZER})
    message(STATUS "Sanatizer ENABLED")
  set(CXX_EXTRA_DEBUG "${CXX_EXTRA_DEBUG} -fsanitize=address")
endif()

# Explicit Exceptions
option(EXPLICIT_EXCEPTIONS "Explicitly enable C++ exceptions." FALSE)
if(${EXPLICIT_EXCEPTIONS})
  set(CXX_EXTRA "${CXX_EXTRA} -fexceptions")
endif()
