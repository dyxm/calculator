cmake_minimum_required(VERSION 3.8)
project(calculator)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c recursionFunction.h generalProgram.h)
add_executable(calculator ${SOURCE_FILES})