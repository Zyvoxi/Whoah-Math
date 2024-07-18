[![Build Whoah-Math](https://github.com/Zyvoxi/Whoah-Math/actions/workflows/main.yml/badge.svg?branch=main)](https://github.com/Zyvoxi/Whoah-Math/actions/workflows/main.yml)

# Whoah Math

**Whoah Math** é um projeto em C++ que oferece uma interface de linha de comando para realizar cálculos matemáticos avançados. O projeto inclui funções para calcular raízes, fatorial, potência, logaritmo, média, módulo, derivada e integral de polinômios.

## Funcionalidades

O programa permite ao usuário escolher entre as seguintes opções de cálculo:

1. **Calcular o valor de X em uma função de 1º grau**
2. **Calcular o valor de X em uma função de 2º grau**
3. **Calcular o fatorial de um número**
4. **Calcular a potência de um número**
5. **Calcular o logaritmo de um número**
6. **Calcular a média de uma lista de números**
7. **Calcular o módulo de um número**
8. **Calcular a raiz N-ésima de um número**
9. **Calcular a derivada de um polinômio**
10. **Calcular a integral definida de um polinômio**

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

- `CMakeLists.txt`: Arquivo de configuração para CMake.
- `Whoah/Headers/main.hpp`: Cabeçalhos para `main.cpp`.
- `Whoah/Headers/utility_functions.hpp`: Cabeçalhos para `utility_functions.cpp`.
- `Whoah/Headers/math_functions.hpp`: Cabeçalhos para `math_functions.cpp`.
- `Whoah/Headers/math_utils.hpp`: Cabeçalhos para `Whoah/math_utils.cpp`.
- `Whoah/Headers/math_tests.hpp`: Cabeçalhos para `Whoah/math_tests.cpp`.
- `Whoah/main.cpp`: Código principal do aplicativo.
- `Whoah/utility_functions.h`: Funções utilitárias.
- `Whoah/math_functions.h`: Funções matemáticas.
- `Whoah/math_utils.cpp`. Utilitarios matemáticos.
- `Whoah/math_tests.cpp`. Testes matemáticos.
  
## Compilação e Execução

### Compilação no macOS

1. **Instale o Xcode Command Line Tools**:

    ```sh
    xcode-select --install
    ```

2. **Compile o projeto com o Xcode**:

    Navegue até o diretório do projeto e execute:

    ```sh
    xcodebuild -scheme Whoah -configuration Release -derivedDataPath build
    ```

    Após a compilação, o executável estará disponível em `build/Build/Products/Release`.

### Compilação no Ubuntu

1. **Instale as dependências necessárias**:

    ```sh
    sudo apt update
    sudo apt install build-essential cmake
    ```

2. **Compile o projeto com CMake e Make**:

    Navegue até o diretório do projeto e execute:

    ```sh
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release ..
    cmake --build .
    ```

3. **O executável estará disponível em `build/Whoah-Math`.**

### Compilação no Windows

1. **Instale o Visual Studio** (incluindo ferramentas de C++).

2. **Compile o projeto com CMake e MSBuild**:

    Navegue até o diretório do projeto e execute:

    ```sh
    mkdir build
    cd build
    cmake -G "Visual Studio 17 2022" ..
    cmake --build . --config Release
    ```

3. **O executável estará disponível em `build/Release/Whoah-Math.exe`.**

## Uso

Quando o programa for executado, você verá um menu de opções. Escolha uma das opções digitando o número correspondente e pressione Enter. O programa solicitará os parâmetros necessários para o cálculo e exibirá o resultado.

## Debug

Se você deseja executar o programa em modo de depuração, certifique-se de definir a macro `DEBUG` no código-fonte. Isso permitirá o acesso a funcionalidades adicionais, como a execução de testes matemáticos.

## Contribuição

Sinta-se à vontade para contribuir com o projeto! Você pode abrir issues, enviar pull requests e compartilhar suas melhorias.

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).
