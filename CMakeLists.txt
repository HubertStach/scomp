cmake_minimum_required(VERSION 4.0)
project(ccomp)

set(CMAKE_CXX_STANDARD 20)

add_executable(ccomp main.cpp
        lexer.cpp
        lexer.h
        code_gen.cpp
        code_gen.cpp
        code_gen.h
        parser.cpp
        parser.h)
