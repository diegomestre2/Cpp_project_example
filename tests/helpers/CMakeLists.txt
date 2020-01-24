set(TEST_HELPERS test_helpers.cpp)

add_library(test_helpers STATIC ${TEST_HELPERS})

if(NOT WIN32)
  target_link_libraries(test_helpers cpp_project_example_library)
endif()