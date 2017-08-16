cmake_minimum_required(VERSION 3.7)
project(library)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp libraryItem.cpp book.cpp shelf.cpp)
add_executable(library ${SOURCE_FILES})