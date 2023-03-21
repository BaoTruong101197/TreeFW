cmake_minimum_required(VERSION 3.9)

project(tree)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(tree ${SOURCES})