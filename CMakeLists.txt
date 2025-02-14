cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(Whoah-Math)

# Define o padrão de compilação para C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define o diretório onde o GMP está localizado
if (MSVC)
    set(GMP_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/gmp/include")
    set(GMP_LIBRARY "${CMAKE_SOURCE_DIR}/gmp/lib/libgmp-10.dll")
endif()

# Adiciona os diretórios de cabeçalho
include_directories(Whoah/Headers)
include_directories(${GMP_INCLUDE_DIR})

# Adicione o diretório da biblioteca
link_directories(${CMAKE_SOURCE_DIR}/gmp/lib)

# Adiciona os arquivos fonte
file(GLOB SOURCES "Whoah/*.cpp")

# Cria o executável a partir dos arquivos fonte
add_executable(${PROJECT_NAME} ${SOURCES})

# Vincule a biblioteca GMP ao executável
target_link_libraries(${PROJECT_NAME} PRIVATE ${GMP_LIBRARY})

# Configurar o CRT para vinculação estática
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /MT)
endif()
