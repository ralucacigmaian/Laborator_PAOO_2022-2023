#CMake version
cmake_minimum_required(VERSION 3.2)

set(myproject "Tema1")
#Project name
project(${myproject})

#Define the executable
add_executable(${PROJECT_NAME} main.cpp)