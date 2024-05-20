cmake_minimum_required(VERSION 3.28)
project(03_Operators_Minesweeper)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(03_Operators_Minesweeper
        cell.cpp
        cell.h
        grid.cpp
        grid.h
        int2.cpp
        int2.h
        main.cpp)
