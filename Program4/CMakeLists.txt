cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Puzzle.cpp Puzzle.h Sudoku.cpp Sudoku.h)
add_executable(Program4 ${SOURCE_FILES})