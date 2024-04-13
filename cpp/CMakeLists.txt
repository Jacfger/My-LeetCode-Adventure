cmake_minimum_required(VERSION 3.10)
project(LeetCodeAdventure)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find fmt library
find_package(fmt REQUIRED)

# Add the executable
# You need to pass the solution file path when invoking CMake, e.g.,
# cmake -DSOLUTION_FILE=solution.cpp ..
if(NOT DEFINED SOL)
    message(FATAL_ERROR "SOL not provided. Set with -DSOL=path/to/your_solution.cpp")
endif()

add_executable(solution ${SOL})

# Link fmt library
target_link_libraries(solution fmt::fmt)