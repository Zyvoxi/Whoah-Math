cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(Whoah-Math)

# Define o padrão de compilação para C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona os diretórios de cabeçalho
include_directories(Whoah/Headers)
include_directories(C:/msys64/mingw64/include)

# Adiciona os arquivos fonte
file(GLOB SOURCES "Whoah/*.cpp")

# Define o caminho de pesquisa para pacotes e bibliotecas
set(CMAKE_PREFIX_PATH "C:/msys64/mingw64")

# Encontra a biblioteca GMP
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(GMP REQUIRED)

# Inclui diretórios e bibliotecas da GMP
include_directories(${GMP_INCLUDE_DIRS})
link_directories(${GMP_LIBRARY_DIRS})

# Cria o executável a partir dos arquivos fonte
add_executable(${PROJECT_NAME} ${SOURCES})

# Vincula a biblioteca GMP ao executável
target_link_libraries(${PROJECT_NAME} ${GMP_LIBRARIES})

# Adiciona opções para compilação estática
if (MSVC)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
endif()

# Inclui o CPack para a criação de pacotes de distribuição
include(CPack)

set(CPACK_PACKAGE_NAME "Whoah-Math")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_GENERATOR "ZIP")

# Inclui o executável e as DLLs necessárias no pacote
install(TARGETS ${PROJECT_NAME} DESTINATION .)
