message(STATUS "Building tests.")

# Add includes (*.hpp files)
include_directories(include)

# Add directories
add_subdirectory(helpers)
add_subdirectory(hello)

# Add executable file (*.cpp file)
add_executable(tests test.cpp ${ALL_OBJECT_FILES})

# Add executable compiler features
target_compile_features(tests PRIVATE cxx_std_17)

# Add Catch2 for tests
message("-- Fetching Catch2...")
include(FetchContent)
# Download and compile Catch lib for unit tests
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.0.0-preview3)
# Make it available
FetchContent_MakeAvailable(Catch2)
message("-- Catch2 Available")

# Add libraries for linking
target_link_libraries(tests PUBLIC test_helpers Catch2 Catch2WithMain cpp_project_example_library) # Uncomment if Catch2 is intalled

# This is specific for Catch2
# include(CTest)
# include(ParseAndAddCatchTests) # Uncomment if Catch2 is intalled
# ParseAndAddCatchTests(tests)	 # Uncomment if Catch2 is intalled

