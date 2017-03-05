cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Puzzle.cpp Puzzle.h Sudoku.cpp Sudoku.h Fitness.cpp Fitness.h SudokuFitness.cpp SudokuFitness.h Reproduction.cpp Reproduction.h SudokuOffspring.cpp SudokuOffspring.h)
add_executable(Program4 ${SOURCE_FILES})