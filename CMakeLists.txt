cmake_minimum_required(VERSION 3.10)

# Defina o nome do projeto
project(Whoah-Math)

# Adicione o executável
add_executable(Whoah-Math
    Whoah/main.cpp
    Whoah/utility_functions.cpp
    Whoah/math_functions.cpp
)

# Inclua os diretórios de cabeçalho
include_directories(Whoah/Headers)
target_link_libraries(Whoah-Math gcc stdc++)
