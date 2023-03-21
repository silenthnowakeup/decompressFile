cmake_minimum_required(VERSION 3.24)
project(decompressFile C)

set(CMAKE_C_STANDARD 11)

add_executable(decompressFile main.c functions.c)
