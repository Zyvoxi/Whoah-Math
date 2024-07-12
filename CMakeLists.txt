cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static")
project(Whoah VERSION 1.0)
add_executable(Main Whoah/main.cpp)
