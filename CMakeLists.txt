project(tree)

include_directories(include)

#set(SOURCES src/main.cpp src/application.cpp)

file(GLOB SOURCES "src/*.cpp")

add_executable(tree ${SOURCES})