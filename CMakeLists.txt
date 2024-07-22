cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(Whoah-Math)

# Define o padrão de compilação para C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona os diretórios de cabeçalho
include_directories(Whoah/Headers)

# Adiciona os arquivos fonte
file(GLOB SOURCES "Whoah/*.cpp")

# Encontra a biblioteca GMP
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(GMP REQUIRED)

# Inclui diretórios e bibliotecas da GMP
include_directories(${GMP_INCLUDE_DIRS})
link_directories(${GMP_LIBRARY_DIRS})

# Cria o executável a partir dos arquivos fonte
add_executable(${PROJECT_NAME} ${SOURCES})

# Vincula a biblioteca GMP ao executável
target_link_libraries(${PROJECT_NAME} GMP::GMP)

# Adiciona opções para compilação estática

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

install(TARGETS ${PROJECT_NAME} DESTINATION .)
