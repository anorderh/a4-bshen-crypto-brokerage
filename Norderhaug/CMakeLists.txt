cmake_minimum_required(VERSION 3.21)
project(Norderhaug)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

include_directories(.)

add_executable(Norderhaug
        cryptoexchange.h
        log.c
        log.h
        main.cpp
        Brokerage.cpp
        Brokerage.h
        Service.cpp
        Service.h
        Synch.cpp
        Synch.h
        Request.cpp
        Request.h
        Buffer.cpp
        Buffer.h
        Producer.cpp
        Producer.h
        Consumer.cpp
        Consumer.h
        )
