cmake_minimum_required(VERSION 3.8)
project(L07_SortingYSearching)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES main.cpp src/ejercicios.cpp tests/contieneElementos.cpp tests/naipesFaltantes.cpp tests/dameBache.cpp tests/dameBache1.cpp tests/maximoRotadas.cpp tests/perteneceRotadas.cpp)
add_executable(L07_SortingYSearching ${SOURCE_FILES})

target_link_libraries(L07_SortingYSearching gtest gtest_main)

