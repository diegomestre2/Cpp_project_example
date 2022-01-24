set(HELLO_TEST hello_tests.cpp)

add_library(hello_test STATIC ${HELLO_TEST})

if(NOT WIN32)
  target_link_libraries(hello_test cpp_project_example_library Catch2 Catch2WithMain)
endif()