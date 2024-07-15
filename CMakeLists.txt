cmake_minimum_required(VERSION 3.10)
project(Whoah-Math)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8 -static-libgcc -static-libstdc++ -static")
add_executable(Whoah-Math
    Whoah/main.cpp
    Whoah/utility_functions.cpp
    Whoah/math_functions.cpp
)
include_directories(Whoah/Headers)
target_link_libraries(Whoah-Math gcc stdc++)
