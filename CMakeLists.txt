cmake_minimum_required(VERSION 3.14)
project(HelloThread)

set(CMAKE_CXX_STANDARD 11)

add_executable(HelloCplus main.cpp AbstractThread.cpp AbstractThread.h UserServerThread.cpp UserServerThread.h UserClientThread.cpp UserClientThread.h)