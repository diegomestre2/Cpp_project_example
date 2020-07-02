
# CMakeLists.txt for the Cpp_exercises project
#
# Notes:
#
# To use a different compiler with CMake, run it as follows:
#
# cmake -D CMAKE_C_COMPILER=/path/to/your/cc -D CMAKE_CXX_COMPILER=/path/to/your/c++ your_project_dir
#
#
cmake_minimum_required (VERSION 3.1)

# My own cmake Modules
# 
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/" "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")
#
#

# -----------------------------------
# Project name, version & build type
# -----------------------------------



if (NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")


# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
       Ex: 
           mkdir build/debug
           cd build/debug
           cmake ..
")
endif()

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    # This is the top-level project.
	PROJECT (Cpp_principles)

#	# No versioning for now
#
#	set(PROJECT_MAJOR_VERSION 0)
#	set(PROJECT_MINOR_VERSION 1)
#	set(PROJECT_PATCH_VERSION 0)
#	set(PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_VERSION})
endif()


# ----------------------------
# General C/C++ build settings
# ----------------------------

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wpedantic" )
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -Og -g -march=native")
SET(CMAKE_C_ARCHIVE_FINISH   "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
SET(CMAKE_CXX_ARCHIVE_FINISH "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")

#SET(CMAKE_BUILD_TYPE distribution)

include_directories( "src/include" )

# ---------------------------------------
# Add all sources to the variable SOURCES
# ---------------------------------------
#file(GLOB SOURCES "src/Chapter_6/*.cpp")

# ------------------
# Add link_libraries
# ------------------
add_library(sources src/Chapter_6/calculator.cpp src/Chapter_6/name_value.cpp src/Chapter_6/english_gramma.cpp src/Chapter_6/game.cpp src/Chapter_8/my.cpp src/Chapter_9/chrono.cpp src/Chapter_9/book.cpp)
target_include_directories(sources PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

# -----------------------
#  Add sources separately
# -----------------------
set(MAIN src/main.cpp)
set(EXERCISES src/Chapter_2/exercises.cpp)
set(AGE src/Chapter_3/age.cpp)
set(OPERATIONS src/Chapter_3/operations.cpp)
set(REPEATED src/Chapter_3/repeated_words.cpp)
set(CONVERTIONS src/Chapter_3/convertions.cpp)
set(CHAP4 src/Chapter_4/coins_conversion.cpp)
set(TRY4 src/Chapter_4/try_this.cpp)
set(DRILL1 src/Chapter_2/drill.cpp)
set(DRILL3 src/Chapter_3/drill.cpp)
set(DRILL4 src/Chapter_4/drill4.cpp)
set(DRILL5 src/Chapter_5/drill5.cpp)
set(DRILL6 src/Chapter_6/drill6.cpp)
set(EXERCISES3 src/Chapter_3/exercises.cpp)
set(EXERCISES4 src/Chapter_4/exercises_4.cpp)
set(EXERCISES5 src/Chapter_5/exercises_5.cpp)
set(EXERCISES6 src/Chapter_6/exercises_6.cpp)
set(MAIN_CH6 src/Chapter_6/main.cpp)
set(CALC2 src/Chapter_6/calculator02buggy.cpp)
set(CALC3 src/Chapter_7/calculator3.cpp)
set(CHAP_8 src/Chapter_8/use.cpp)
set(NAMESPACE src/Chapter_8/namespace.cpp)
set(CHAP_9 src/Chapter_9/date_use.cpp)
set(NAME_PAIR src/Chapter_9/name_pair.cpp)


# -----------------------
# Main target(s)
# -----------------------

#[[if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib/")
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib/")
endif()

cuda_add_library(
	cuda-api-wrappers
	src/cuda/api/device_properties.cpp
	src/cuda/api/profiling.cpp
)]]

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)

	#link_libraries(cuda-api-wrappers)
 
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
    # Chapter 02
    add_executable(drill_1 ${DRILL1})
    add_executable(exercises ${EXERCISES})
    #target_link_libraries(drill_1 )
    # Chapter 03
    add_executable(age ${AGE})
    add_executable(operations ${OPERATIONS})
    add_executable(repeated_words ${REPEATED})
    add_executable(convertions ${CONVERTIONS})
    add_executable(drill3 ${DRILL3})
    add_executable(exercises_3 ${EXERCISES3})
    # Chapter 04
    add_executable(chap4 ${CHAP4})
    add_executable(try_this4 ${TRY4})
    add_executable(drill4 ${DRILL4})
    add_executable(exercises_4 ${EXERCISES4})
    # Chapter 05
    add_executable(drill5 ${DRILL5})
    add_executable(exercises_5 ${EXERCISES5})
    # Chapter 06
    add_executable(drill6 ${DRILL6})
    add_executable(exercises_6 ${EXERCISES6})
    #add_executable(mainch6 ${MAIN_CH6})
    #target_link_libraries(mainch6 sources)
    add_executable(calculator2 ${CALC2})
    add_executable(calculator3 ${CALC3})
    target_link_libraries(calculator3 sources)
    # Chapter 08
    add_executable(chap8 ${CHAP_8})
    target_link_libraries(chap8 sources)
    add_executable(namespace ${NAMESPACE})
    # Chapter 09
    add_executable(chap_9 ${CHAP_9})
    target_link_libraries(chap_9 sources)
    add_executable(name_pair ${NAME_PAIR})
    add_executable(main ${MAIN})
    target_link_libraries(main sources)

endif()

# -------------

#[[INSTALL(
	TARGETS cuda-api-wrappers
	ARCHIVE # For CMake, a static library is an ARCHIVE, a dynamic library is a RUNTIME
	DESTINATION lib
	INCLUDES DESTINATION include
	CONFIGURATIONS Release RelWithDebugInfi
)

install(
	DIRECTORY src/cuda
	DESTINATION include
)]]

