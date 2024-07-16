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

# Cria o executável a partir dos arquivos fonte
add_executable(${PROJECT_NAME} ${SOURCES})

# Adiciona opções para compilação estática
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")
set(CMAKE_FIND_LIBRARY_SUFFIXES .lib .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
set(BUILD_SHARED_LIBS OFF) # Desabilita bibliotecas compartilhadas

# Configuração para UTF-8 no Windows
add_definitions(-DUNICODE -D_UNICODE)
add_compile_options("/utf-8")

# Configurações de depuração
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
endif()

# Inclui o CPack para a criação de pacotes de distribuição
include(CPack)

set(CPACK_PACKAGE_NAME "Whoah-Math")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_GENERATOR "ZIP") # Você pode usar diferentes geradores como NSIS para um instalador no Windows

# Inclui o executável e as DLLs necessárias no pacote
install(TARGETS ${PROJECT_NAME} DESTINATION .)
