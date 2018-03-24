cmake_minimum_required(VERSION 3.0)

project(algorithms)

######################
# Build Settings
######################
set (CMAKE_CXX_STANDARD 98)

#####################################
# Build Targets solutions, sample and tests
#####################################
add_subdirectory(solutions)

# To build tests, add option flag -DBUILD_TESTS=1 to cmake command
set(BUILD_TESTS, 0)

if(BUILD_TESTS)
add_subdirectory(tests)
endif()
