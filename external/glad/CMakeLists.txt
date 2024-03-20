cmake_minimum_required(VERSION 3.22)

set(target_name glad)

add_library(${target_name} STATIC
    src/glad.c
    include/glad/glad.h)

target_include_directories(${target_name} PUBLIC ./include)
