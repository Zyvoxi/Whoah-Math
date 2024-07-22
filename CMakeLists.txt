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
# Encontra a biblioteca GMP e força o uso da versão estática
find_package(GMP REQUIRED)
if(GMP_FOUND)
    set(GMP_LIBRARY "${GMP_LIBRARIES}")
    if(NOT GMP_FOUND_STATIC)
        message(FATAL_ERROR "Static GMP library not found")
    endif()
endif()

# Cria o executável a partir dos arquivos fonte
add_executable(${PROJECT_NAME} ${SOURCES})

# Inclui diretórios e bibliotecas da GMP
target_include_directories(${PROJECT_NAME} PRIVATE ${GMP_INCLUDE_DIRS})

# Vincula a biblioteca GMP estaticamente
target_link_libraries(${PROJECT_NAME} PRIVATE ${GMP_LIBRARY})

# Adiciona opções para compilação estática
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
