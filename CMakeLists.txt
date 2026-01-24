cmake_minimum_required(VERSION 4.0)

project(leet
    VERSION 1.0
    LANGUAGES CXX)

file(GLOB_RECURSE SOURCES src/*.cc)

add_library(my_lib ${SOURCES})
target_include_directories(my_lib PUBLIC include/)