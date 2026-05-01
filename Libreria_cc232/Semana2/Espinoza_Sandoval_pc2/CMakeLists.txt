cmake_minimum_required(VERSION 3.10)
project(Espinoza_Sandoval_pc2)
set(CMAKE_CXX_STANDARD 17)

# Collect all .cpp files from the src directory
file(GLOB SOURCES "src/*.cpp")

# Create a LIBRARY from the source files to be shared
add_library(bracket_sequence_lib ${SOURCES})

# Make sure other targets can find the headers from the include directory
target_include_directories(bracket_sequence_lib PUBLIC include)

#Make executable for demos/demo_bracketsequence.cpp
add_executable(demo_bracketsequence demos/demo_bracketsequence.cpp)
target_link_libraries(demo_bracketsequence PRIVATE bracket_sequence_lib)
#Make executable for demos/demo_stackeditor.cpp
add_executable(demo_stackeditor demos/demo_stackeditor.cpp)
target_link_libraries(demo_stackeditor PRIVATE bracket_sequence_lib)

#Make executable for benchmark/bench_bracketsequence.cpp
add_executable(bench_bracketsequence benchmark/bench_bracketsequence.cpp)
target_link_libraries(bench_bracketsequence PRIVATE bracket_sequence_lib)
#Make executable for benchmark/bench_stackeditor.cpp
add_executable(bench_stackeditor benchmark/bench_stackeditor.cpp)
target_link_libraries(bench_stackeditor PRIVATE bracket_sequence_lib)

#Make executable for public_tests/test_bracketsequence.cpp
add_executable(test_public_bracketsequence public_tests/test_public_bracketsequence.cpp)
target_link_libraries(test_public_bracketsequence PRIVATE bracket_sequence_lib)
#Make executable for public_tests/test_stackeditor.cpp
add_executable(test_public_stackeditor public_tests/test_public_stackeditor.cpp)
target_link_libraries(test_public_stackeditor PRIVATE bracket_sequence_lib)

#Make executable for internal_tests/test_bracketsequence.cpp
add_executable(internal_test_bracketsequence internal_tests/test_internal_bracketsequence.cpp)
target_link_libraries(internal_test_bracketsequence PRIVATE bracket_sequence_lib)
#Make executable for internal_tests/test_stackeditor.cpp
add_executable(internal_test_stackeditor internal_tests/test_internal_stackeditor.cpp)
target_link_libraries(internal_test_stackeditor PRIVATE bracket_sequence_lib)