cmake_minimum_required(VERSION 3.13)
project(Final)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Final
        Block.cpp
        Block.h
        Blockchain.cpp
        Blockchain.h
        main.cpp
        sha256.cpp
        sha256.h
        User.cpp
        User.h NamespaceDisplay.h)
