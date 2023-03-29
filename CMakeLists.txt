cmake_minimum_required(VERSION 3.9)

project(tree)

include_directories(include)

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(tree ${SOURCES})