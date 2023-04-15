cmake_minimum_required(VERSION 3.21)
project(Norderhaug)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Norderhaug
        cryptoexchange.h
        log.c
        log.h
        main.cpp)
