cmake_minimum_required(VERSION 3.11)
project(binary)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-export-dynamic")

add_executable(binary binary.cpp)
