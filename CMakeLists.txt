cmake_minimum_required(VERSION 3.18.4)

project(Network_Simulator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

message("Compiler to use: " ${CMAKE_CXX_COMPILER})

if (CMAKE_BUILD_TYPE EQUAL "Debug")
    message(STATUS "Debug mode")
	set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
	set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
endif (CMAKE_BUILD_TYPE EQUAL "Debug")

#Set default compile flags for G++.
if(CMAKE_COMPILER_IS_GNUCXX)
	message(STATUS "G++ Detected!, adding compile flags!")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic-errors -ggdb -std=c++2a")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")

add_subdirectory(src)