cmake_minimum_required(VERSION 3.23)
project(brokerage)

set(CMAKE_CXX_STANDARD 14)

add_executable(brokerage main.cpp Brokerage.cpp Brokerage.h Buffer.cpp Buffer.h
        Consumer.cpp Consumer.h cryptoexchange.h log.c log.h Producer.cpp Producer.h
        Request.cpp Request.h Service.cpp Service.h Synch.cpp Synch.h)
