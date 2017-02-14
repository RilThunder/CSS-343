cmake_minimum_required(VERSION 3.6)
project(Program2_ShortestPath)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        data31.txt
        data32.txt
        dataUWB.txt
        graphl.cpp
        graphl.h
        graphm.cpp
        graphm.h
        image.png
        image2.png
        Lab3.cpp
        lab3output.txt
        nodedata.cpp
        nodedata.h)

add_executable(Program2_ShortestPath ${SOURCE_FILES})