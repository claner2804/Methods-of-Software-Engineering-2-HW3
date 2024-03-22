cmake_minimum_required(VERSION 3.27)
project(HW3)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW3 main.cpp
        character.cpp
        character.h
        hero.cpp
        hero.h
        item.cpp
        item.h)
