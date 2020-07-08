



# Add includes (*.hpp files)
include_directories(${PROJECT_SOURCE_DIR}/third_party/catch)
include_directories(include)

# Add directories
add_subdirectory(helpers)
add_subdirectory(hello)

# Add executable file (*.cpp file)
add_executable(tests test.cpp ${ALL_OBJECT_FILES})

# Add executable compiler features
target_compile_features(tests PRIVATE cxx_std_17)

# Add libraries for linking
target_link_libraries(tests PRIVATE cpp_project_example_library test_helpers #[[Catch2::Catch2]]) # Uncomment if Catch2 is intalled

# This is specific for Catch2
include(CTest)
# include(ParseAndAddCatchTests) # Uncomment if Catch2 is intalled
# ParseAndAddCatchTests(tests)	 # Uncomment if Catch2 is intalled

if(EXISTS "${PROJECT_SOURCE_DIR}/third_party/catch/include")
    file(COPY  ${PROJECT_SOURCE_DIR}/third_party/catch/include/catch2/catch.hpp DESTINATION "${PROJECT_SOURCE_DIR}/third_party/catch/")
    file(REMOVE_RECURSE ${PROJECT_SOURCE_DIR}/third_party/catch/include ${PROJECT_SOURCE_DIR}/third_party/catch/lib ${PROJECT_SOURCE_DIR}/third_party/catch/share)
endif()
