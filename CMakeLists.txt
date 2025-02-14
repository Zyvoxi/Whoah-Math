cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(Whoah-Math)

# Define o padrão de compilação para C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define o diretório onde o GMP está localizado
if (MSVC)
    set(GMP_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/gmp/include")
    find_library(GMP_LIBRARY NAMES libgmp-10 PATHS "${CMAKE_SOURCE_DIR}/gmp/lib" NO_DEFAULT_PATH)
    if (NOT GMP_LIBRARY)
        message(FATAL_ERROR "GMP library not found")
    endif()
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

# Copiar o libgmp-10.dll para o diretório de saída
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/gmp/lib/libgmp-10.dll"
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
