cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard")

set(PROJECT_NAME "EdgeDetections")

project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/Bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/Bin)

# Gorgon package required for image processing part
find_package(Gorgon REQUIRED)

# Min c++ version is 17
add_compile_options(-std=c++17)

add_executable(${PROJECT_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
)

linkgorgon(${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
include_directories(${CMAKE_CURRENT_LIST_DIR}/Source/)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Tests/)


enable_testing()
