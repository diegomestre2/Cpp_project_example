# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")
# set(HEADER_LIST "${WhiteBoxCompression_SOURCE_DIR}/include/modern/lib.hpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(hello_library hello.cpp ${HEADER_LIST})
# We need this directory, and users of our library will need it too
target_include_directories(hello_library PUBLIC "${PROJECT_SOURCE_DIR}/include")
# All users of this library will need at least C++11
target_compile_features(hello_library PUBLIC cxx_std_11)
# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:hello_library>
    PARENT_SCOPE)