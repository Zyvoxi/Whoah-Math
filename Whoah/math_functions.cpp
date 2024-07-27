//
//  math_functions.cpp
//  Whoah
//
//  Created by IV. on 15/07/24.
//

#include "math_functions.hpp"
#include "math_utils.hpp"
#include "utility_functions.hpp"
#include <iostream>
#include <gmp.h>
#include <sstream>
#include <iomanip>
#include <cmath>
    using namespace std;

// MARK: Raiz de X - 1º
void funcRX() {
    cout << "Descobrindo o valor de X em uma função de 1º grau.\n" << endl;

    double a;
    while (true) {
        try {
            a = getValidatedInput("Digite o valor de `a`: ");
            if (a == 0) throw invalid_argument("`a` não pode ser 0.");
            break;
        } catch (const invalid_argument& e) {
            handleError(e.what());
        }
    }

    double b = getValidatedInput("Digite o valor de `b`: ");
    double x = calcRX(a, b);

    clearScreen();
    printFormulaRX(a, b, x);

    returnOptions();
}

// MARK: Raiz de X - 2º
void funcRX2() {
    cout << "Descobrindo o valor de X em uma função de 2º grau.\n" << endl;

    double a;
    while (true) {
        try {
            a = getValidatedInput("Digite o valor de `a`: ");
            if (a == 0) throw invalid_argument("`a` não pode ser 0.");
            break;
        } catch (const invalid_argument& e) {
            handleError(e.what());
        }
    }

    double b = getValidatedInput("Digite o valor de `b`: ");
    double c = getValidatedInput("Digite o valor de `c`: ");

    double delta = calcDelta(a, b, c);
    double x1, x2;
    calcRX2(a, b, delta, x1, x2);

    clearScreen();
    printDelta(a, b, c, delta);

    if (delta < 0) {
        cout << "\nDelta é negativo, então as raízes não fazem parte dos números reais, portanto não iremos encontrá-las.\n";
    } else {
        printFormulaRX2(b, delta, a);
        cout << "X¹ = " << formatNumber(x1)
             << endl << "X² = " << formatNumber(x2) << endl;
    }
    returnOptions();
}

// MARK: Fatorial
void funcFatorial() {
    cout << "Calculando o fatorial de um número.\n" << endl;

    double n;
    while (true) {
        try {
            n = getValidatedInput("Digite um número inteiro não-negativo: ");
            if (n != floor(n) || n < 0) throw invalid_argument("Por favor digite um número inteiro não-negativo.");
            break;
        } catch (const invalid_argument& e) {
            handleError(e.what());
        }
    }

    try {
        unsigned int intN = static_cast<unsigned int>(n);
        mpz_t result;
        mpz_init(result);
        calcFatorial(intN, result);
        clearScreen();
        printFormulaFatorial(intN, result);
        mpz_clear(result);
    } catch (const invalid_argument& e) {
        handleError(e.what());
    } catch (const overflow_error& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Potencia
void funcPotencia() {
    cout << "Calculando a potência de um número.\n" << endl;

    double base = getValidatedInput("Digite a base: ");
    double exponent = getValidatedInput("Digite o expoente: ");

    double result = power(base, exponent);
    clearScreen();
    printFormulaPotencia(base, exponent, result);

    returnOptions();
}

// MARK: Logaritmo
void funcLogaritmo() {
    cout << "Calculando o logaritmo de um número.\n" << endl;

    double value, base;
    while (true) {
        try {
            value = getValidatedInput("Digite o valor: ");
            base = getValidatedInput("Digite a base: ");
            if (value <= 0 || base <= 0 || base == 1) throw invalid_argument("O valor e a base devem ser positivos e a base deve ser diferente de 1.");
            break;
        } catch (const invalid_argument& e) {
            handleError(e.what());
        }
    }

    try {
        double result = calcLog(value, base);
        clearScreen();
        printFormulaLogaritmo(value, base, result);
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Média
void funcMedia() {
    cout << "Calculando a média de uma lista de números.\n" << endl;

    vector<double> numbers = processNumbersFromInput();

    try {
        if (!numbers.empty()) {
            double result = average(numbers);
            clearScreen();
            printFormulaMedia(numbers, result);
        } else {
            throw invalid_argument("Nenhum número válido foi fornecido.");
        }
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Módulo
void funcModulo() {
    cout << "Calculando o módulo de um número.\n" << endl;

    double num = getValidatedInput("Digite um número para calcular o módulo: ");

    cout << "O módulo de | " << formatNumber(num) << " | é " << formatNumber(mCalc(num)) << endl;

    returnOptions();
}

// MARK: Raiz N-ésima
void funcRaizN() {
    cout << "Calculando a Raiz N-ésima de um número\n" << endl;

    double base = getValidatedInput("Digite a base da Raiz: ");
    double index;
    while (true) {
        try {
            index = getValidatedInput("Digite o índice da Raiz: ");
            if (index == 0) throw invalid_argument("O índice da raiz não pode ser zero.");
            break;
        } catch (const invalid_argument& e) {
            handleError(e.what());
        }
    }

    try {
        double result = calcRaizN(base, index);
        clearScreen();
        printFormulaRaizN(base, index, result);
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Derivada
void funcDerivada() {
    cout << "calcular a derivada de um polinômio.\n" << endl;

    cout << "Insira os coeficientes do polinômio separados por espaços (do maior grau para o menor grau)." << endl;
    vector<double> numbers = processNumbersFromInput();

    try {
        if (!numbers.empty()) {
            vector<double> result = calcDerivada(numbers);
            clearScreen();
            printFormulaDerivada(numbers, result);
        } else {
            throw invalid_argument("Nenhum número válido foi fornecido.");
        }
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Integral Definida
void funcIntegralDefinida() {
    cout << "Calculando a integral definida de um polinômio.\n" << endl;

    cout << "Insira os coeficientes do polinômio separados por espaços (do maior grau para o menor grau)." << endl;
    vector<double> numbers = processNumbersFromInput();

    try {
        if (!numbers.empty()) {
            double a = getValidatedInput("Insira o limite inferior de integração: ");
            double b = getValidatedInput("Insira o limite superior de integração: ");
            double resultado = calcIntegralDefinida(numbers, a, b);
            clearScreen();
            printFormulaIntegralDefinida(numbers, a, b, resultado);
        } else {
            throw invalid_argument("Nenhum número válido foi fornecido.");
        }
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Max Min
void funcMaxMin() {
    cout << "Encontrando o valor máximo e mínimo de uma lista de números.\n" << endl;

    vector<double> numbers = processNumbersFromInput();

    try {
        if (!numbers.empty()) {
            auto maxMin = findMaxMin(numbers);
            clearScreen();
            printMaxMin(numbers, maxMin);
        } else {
            throw invalid_argument("Nenhum número válido foi fornecido.");
        }
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Permutação
void funcPermutacao() {
    cout << "Calculando o número de permutações de um conjunto de elementos.\n" << endl;

    double n, k;
    while (true) {
        try {
            n = getValidatedInput("Insira o número total de elementos (n): ");
            if (n != floor(n) || n < 0) throw invalid_argument("n deve ser um número inteiro positivo.");
            while (true) {
                try {
                    k = getValidatedInput("Insira o número de elementos selecionados (k): ");
                    if (k > n || k < 0 || k != floor(k)) throw invalid_argument("k deve ser um número inteiro positivo e deve estar no intervalo [0, n].");
                    break;
                } catch (const invalid_argument& e) {
                    handleError(e.what());
                }
            }
            break;
        } catch (const invalid_argument& e) {
            handleError(e.what());
        }
    }

    mpz_t resultado;
    mpz_init(resultado);

    try {
        calcPermutacao(resultado, n, k);
        clearScreen();
        printFormulaPermutacao(n, k, resultado);
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    mpz_clear(resultado); // Libere a memória alocada para resultado
    returnOptions();
}

// MARK: Combinação
void funcCombinacao() {
    cout << "Calculando o número de combinações de um conjunto de elementos.\n" << endl;

    double n, k;
    while (true) {
        try {
            n = getValidatedInput("Insira o número total de elementos (n): ");
            if (n != floor(n) || n < 0) throw invalid_argument("n deve ser um número inteiro positivo.");
            while (true) {
                try {
                    k = getValidatedInput("Insira o número de elementos selecionados (k): ");
                    if (k > n || k < 0 || k != floor(k)) throw invalid_argument("k deve ser um número inteiro positivo e deve estar no intervalo [0, n].");
                    break;
                } catch (const invalid_argument& e) {
                    handleError(e.what());
                }
            }
            break;
        } catch (const invalid_argument& e) {
            handleError(e.what());
        }
    }

    try {
        long long resultado = calcCombinacao(n, k);
        printFormulaCombinacao(n, k, resultado);
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Média Geométrica
void funcMGeometrica() {
    cout << "Calculando a média geométrica de uma lista de números.\n" << endl;

    vector<double> numbers = processNumbersFromInput();

    try {
        if (!numbers.empty()) {
            double resultado = calcMGeometrica(numbers);
            clearScreen();
            cout << "A média geométrica é: " << endl;
            printFormulaMGeometrica(numbers, resultado);
        } else {
            throw invalid_argument("Nenhum número válido foi fornecido.");
        }
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Média Harmônica
void funcMHarmonica() {
    cout << "Calculando a média harmônica de uma lista de números.\n" << endl;

    vector<double> numbers = processNumbersFromInput();

    try {
        if (!numbers.empty()) {
            double resultado = calcMHarmonica(numbers);
            clearScreen();
            cout << "A média harmônica é: " << endl;
            printFormulaMHarmonica(numbers, resultado);
        } else {
            throw invalid_argument("Nenhum número válido foi fornecido.");
        }
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Mediana
void funcMediana() {
    cout << "Calculando a mediana de uma lista de números.\n" << endl;

    vector<double> numbers = processNumbersFromInput();

    try {
        if (!numbers.empty()) {
            double resultado = calcMediana(numbers);
            clearScreen();
            printFormulaMediana(numbers, resultado);
        } else {
            throw invalid_argument("Numnhum número válido foi fornecido.");
        }
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Desvio Padrão Amostral
void funcDPAmostral() {
    cout << "Calculando o desvio padrão amostral de uma lista de numeros.\n" << endl;
    
    vector<double> numbers = processNumbersFromInput();

    try {
        if (!numbers.empty()) {
            double resultado = calcDPAmostral(numbers);
            clearScreen();
            printFormulaDPAmostral(numbers, resultado);
        } else {
            throw invalid_argument("Nenhum número válido foi fornecido.");
        }
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Variância
void funcVariancia() {
    cout << "Calculando a variância amostral de um conjunto de numeros.\n" << endl;
    
    vector<double> numbers = processNumbersFromInput();

    try {
        if (!numbers.empty()) {
            double resultado = calcVariancia(numbers);
            clearScreen();
            printFormulaVariancia(numbers, resultado);
        } else {
            throw invalid_argument("Nenhum número válido foi fornecido.");
        }
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}
