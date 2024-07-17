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
#include <sstream>
#include <iomanip>
#include <cassert>
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
            n = getValidatedInput("Digite um número inteiro não-negativo (≤ 65): ");
            if (n != floor(n) || n < 0) throw invalid_argument("Por favor digite um número inteiro não-negativo.");
            if (n > 65) throw overflow_error("Por favor digite um número menor ou igual a 65.");
            break;
        } catch (const invalid_argument& e) {
            handleError(e.what());
        } catch (const overflow_error& e) {
            handleError(e.what());
        }
    }

    try {
        int intN = static_cast<int>(n);
        unsigned long long result = calcFatorial(intN);
        clearScreen();
        printFormulaFatorial(intN, result);
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

// MARK: Testes Mátematicos
void runMathTests() {
    cout << "Executando testes unitários...\n";

    // Testes para calcRX
    assert(calcRX(2, -4) == 2);
    assert(calcRX(1, -1) == 1);
    assert(calcRX(10, 0) == 0);  // Caso normal
    assert(calcRX(-5, 10) == 2);  // Coeficiente 'a' negativo
    // Casos de borda para calcRX
    try {
        calcRX(0, 1);
        assert(false); // Deve lançar exceção
    } catch (const invalid_argument& e) {
        assert(true); // Exceção esperada
    }

    // Testes para calcDelta
    assert(calcDelta(1, -3, 2) == 1);
    assert(calcDelta(1, 2, 1) == 0);
    assert(calcDelta(1, 0, -4) == 16);
    // Casos de borda para calcDelta
    assert(calcDelta(1, 0, 0) == 0);

    // Testes para calcRX2
    double x1, x2;
    calcRX2(1, -3, 1, x1, x2);
    assert(x1 == 2 && x2 == 1);
    calcRX2(10, 20, 1600, x1, x2);
    assert(x1 == 1 && x2 == -3);

    // Testes para factorial
    assert(calcFatorial(0) == 1);
    assert(calcFatorial(5) == 120);
    // Casos de borda para factorial
    try {
        calcFatorial(-1);
        assert(false); // Deve lançar exceção
    } catch (const invalid_argument&) {
        assert(true); // Exceção esperada
    }
    try {
        calcFatorial(66);
        assert(false); // Deve lançar exceção
    } catch (const overflow_error&) {
        assert(true); // Exceção esperada
    }

    // Testes para power
    assert(power(2, 3) == 8);
    assert(power(5, 0) == 1);
    // Casos de borda para power
    assert(power(0, 0) == 1); // Definido como 1 por convenção
    assert(power(0, 5) == 0);
    assert(power(-2, 2) == 4);
    assert(power(-2, 3) == -8);

    // Testes para calcLog
    assert(calcLog(8, 2) == 3);
    assert(calcLog(1, 10) == 0);
    // Casos de borda para calcLog
    try {
        calcLog(-1, 10);
        assert(false); // Deve lançar exceção
    } catch (const invalid_argument&) {
        assert(true); // Exceção esperada
    }
    try {
        calcLog(10, -1);
        assert(false); // Deve lançar exceção
    } catch (const invalid_argument&) {
        assert(true); // Exceção esperada
    }
    try {
        calcLog(10, 1);
        assert(false); // Deve lançar exceção
    } catch (const invalid_argument&) {
        assert(true); // Exceção esperada
    }

    // Testes para average
    vector<double> nums1 = {1, 2, 3, 4, 5};
    assert(average(nums1) == 3);
    vector<double> nums2 = {10, 20, 30};
    assert(average(nums2) == 20);
    // Casos de borda para average
    try {
        vector<double> empty;
        average(empty);
        assert(false); // Deve lançar exceção
    } catch (const invalid_argument&) {
        assert(true); // Exceção esperada
    }

    // Testes para mCalc
    assert(mCalc(-5) == 5);
    assert(mCalc(5) == 5);
    // Casos de borda para mCalc
    assert(mCalc(0) == 0);

    // Testes para calcRaizN
    assert(calcRaizN(27, 3) == 3);
    assert(calcRaizN(16, 4) == 2);
    // Casos de borda para calcRaizN
    try {
        calcRaizN(27, 0);
        assert(false); // Deve lançar exceção
    } catch (const invalid_argument&) {
        assert(true); // Exceção esperada
    }

    cout << "Todos os testes foram executados com sucesso!\n";

    returnOptions();
}
