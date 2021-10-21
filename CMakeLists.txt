cmake_minimum_required(VERSION 3.20)
project(List)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(List
        .idea/.gitignore
        .idea/List.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        .gitignore
        List.h
        main.cpp)
