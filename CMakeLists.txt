cmake_minimum_required(VERSION 3.25)
project(Distributeur)

set(CMAKE_CXX_STANDARD 23)

add_executable(Distributeur src/main.cpp src/Database.h src/Database.cpp)
