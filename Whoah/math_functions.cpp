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
    cout << "Calculando a média de uma lista de números.\n"
         << endl << "Digite os números separados por espaço (pressione Enter para finalizar): ";

    string input;
    getline(cin, input);
    istringstream stream(input);

    vector<double> numbers;
    string token;
    while (stream >> token) {
        if (isBrazilianNumber(token)) {
            string c = convertBrazilianToAmerican(token);
            double n;
            if (isNumber(c)) {
                istringstream(c) >> n;
                numbers.push_back(n);
            } else {
                handleError("Número inválido ignorado: " + token);
            }
        } else {
            handleError("Número inválido ignorado: " + token);
        }
    }

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
    cout << "Insira os coeficientes do polinômio separados por espaços (do maior grau para o menor grau): ";

    string input;
    getline(cin, input);
    istringstream stream(input);

    vector<double> numbers;
    string token;
    while (stream >> token) {
        if (isBrazilianNumber(token)) {
            string c = convertBrazilianToAmerican(token);
            double n;
            if (isNumber(c)) {
                istringstream(c) >> n;
                numbers.push_back(n);
            } else {
                handleError("Número inválido ignorado: " + token);
            }
        } else {
            handleError("Número inválido ignorado: " + token);
        }
    }

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
    cout << "Insira os coeficientes do polinômio separados por espaços (do maior grau para o menor grau): ";

    string input;
    getline(cin, input);
    istringstream stream(input);

    vector<double> numbers;
    string token;
    while (stream >> token) {
        if (isBrazilianNumber(token)) {
            string c = convertBrazilianToAmerican(token);
            double n;
            if (isNumber(c)) {
                istringstream(c) >> n;
                numbers.push_back(n);
            } else {
                handleError("Número inválido ignorado: " + token);
            }
        } else {
            handleError("Número inválido ignorado: " + token);
        }
    }

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
    cout << "Insira os números separados por espaços: ";

    string input;
    getline(cin, input);
    istringstream stream(input);

    vector<double> numbers;
    string token;
    while (stream >> token) {
        if (isBrazilianNumber(token)) {
            string c = convertBrazilianToAmerican(token);
            double n;
            if (isNumber(c)) {
                istringstream(c) >> n;
                numbers.push_back(n);
            } else {
                handleError("Número inválido ignorado: " + token);
            }
        } else {
            handleError("Número inválido ignorado: " + token);
        }
    }

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
