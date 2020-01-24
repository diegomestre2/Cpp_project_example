# Add includes (*.hpp files)
include_directories(../third_party/catch)
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
