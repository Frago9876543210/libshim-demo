cmake_minimum_required(VERSION 3.11)
project(injector)

set(CMAKE_CXX_STANDARD 11)

#libshim
include(FetchContent)

set(LIBSHIM_BUILD_TYPE "STATIC" CACHE INTERNAL "")
set(SYMBOLS_SHIM_PATH "${PROJECT_SOURCE_DIR}/shim_demo" CACHE INTERNAL "")
FetchContent_Declare(shim
    GIT_REPOSITORY https://github.com/Frago9876543210/libshim
    GIT_TAG 1.0.0)
FetchContent_MakeAvailable(shim)

add_library(injector SHARED injector.cpp)
target_link_libraries(injector PRIVATE shim)
