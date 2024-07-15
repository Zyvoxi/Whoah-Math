cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(Whoah-Math)

# Adicione todos os arquivos fonte
set(SOURCES
    main.cpp
    utility_functions.cpp
    math_functions.cpp
)

# Adicione os diretórios de cabeçalho
include_directories(Headers)

# Crie o executável
add_executable(Whoah ${SOURCES})
