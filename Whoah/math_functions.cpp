//
//  math_functions.cpp
//  Whoah
//
//  Created by IV. on 15/07/24.
//

#include "math_functions.h"
#include "utility_functions.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
    using namespace std;

// MARK: Raiz de X - 1º
double calcRX(double a, double b) {
    return -b / a;
}

void printFormulaRX(double a, double b, double x) {
    cout << "y = ax + b"
         << endl << "y = " << formatNumber(a) << (b >= 0 ? "x + " : "x - ") << formatNumber(fabs(b))
         << endl << "0 = " << formatNumber(a) << (b >= 0 ? "x + " : "x - ") << formatNumber(fabs(b))
         << endl << formatNumber(-b) << " = " << formatNumber(a) << "x"
         << endl << formatNumber(-b) << " / " << formatNumber(a) << " = x"
         << endl << "x = " << formatNumber(x) << endl;
}

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
double calcDelta(double a, double b, double c) {
    return (pow(b, 2)) - (4 * a * c);
}

void calcRX2(double a, double b, double delta, double& x1, double& x2) {
    if (delta >= 0) {
        x1 = (-b + sqrt(delta)) / (2.0 * a);
        x2 = (-b - sqrt(delta)) / (2.0 * a);
    }
}

void printDelta(double a, double b, double c, double delta) {
    cout << "Δ = b² - 4ac"
         << endl << "Δ = " << formatNumber(b) << "² - 4 * " << formatNumber(a) << " * " << formatNumber(c)
         << endl << "Δ = " << formatNumber(pow(b, 2)) << (-4 * a * c >= 0 ? " + " : " - ") << formatNumber(fabs(-4 * a * c))
         << endl << "Δ = " << formatNumber(delta) << endl;
}

void printFormulaRX2(double b, double delta, double a) {
    cout << setw(10) << "\n     -b  ±  √Δ "
         << endl << setw(10) << "X = ------------"
         << endl << setw(10) << "         2a    \n" << endl;

    cout << setw(10) << "\n     " << (b >= 0 ? "-" : " ") << formatNumber(fabs(b)) << "  ±  √" << formatNumber(delta)
         << endl << setw(10) << "X = ------------" << (delta >= 100 ? "-----" : "--")
         << endl << setw(10) << "         2 * " << formatNumber(a) << "    \n" << endl;

    cout << setw(10) << "\n     " << (b >= 0 ? "-" : " ") << formatNumber(fabs(b)) << "  ±  " << formatNumber(sqrt(delta))
         << endl << setw(10) << "X = ------------" << (delta >= 100 ? "-----" : "--")
         << endl << setw(10) << "         " << formatNumber(2 * a) << "    \n" << endl;
}

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
unsigned long long factorial(int n) {
    if (n < 0) throw invalid_argument("Fatorial de número negativo não é definido.");
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

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
        unsigned long long result = factorial(static_cast<int>(n));
        cout << "O fatorial de " << formatNumber(n) << " é " << formatNumber(result) << endl;
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Potencia
double power(double base, int exponent) {
    return pow(base, exponent);
}

void funcPotencia() {
    cout << "Calculando a potência de um número.\n" << endl;

    double base = getValidatedInput("Digite a base: ");
    double exponent = getValidatedInput("Digite o expoente: ");

    double result = pow(base, exponent);
    cout << formatNumber(base) << " elevado a " << formatNumber(exponent) << " é " << formatNumber(result) << endl;

    returnOptions();
}

// MARK: Logaritmo
double logarithm(double value, double base) {
    if (value <= 0 || base <= 0 || base == 1) throw invalid_argument("O valor e a base devem ser positivos e a base deve ser diferente de 1.");
    return log(value) / log(base);
}

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
        double result = logarithm(value, base);
        cout << "\nO logaritmo de " << formatNumber(value) << " na base " << formatNumber(base) << " é " << formatNumber(result) << endl;
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Média
double average(const vector<double>& numbers) {
    if (numbers.empty()) throw invalid_argument("A lista de números não pode estar vazia.");
    double sum = 0;
    for (double number : numbers) {
        sum += number;
    }
    return sum / numbers.size();
}

void funcMedia() {
    cout << "Calculando a média de uma lista de números.\n" << endl;
    cout << "Digite os números separados por espaço (pressione Enter para finalizar): ";
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
                cout << "Número inválido ignorado: " << token << endl;
            }
        } else {
            cout << "Número inválido ignorado: " << token << endl;
        }
    }

    try {
        if (!numbers.empty()) {
            double result = average(numbers);
            cout << "A média é " << formatNumber(result) << endl;
        } else {
            throw invalid_argument("Nenhum número válido foi fornecido.");
        }
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}

// MARK: Módulo
double mCalc(double num) {
    return fabs(num);
}

void funcModulo() {
    cout << "Calculando o módulo de um número.\n" << endl;

    double num = getValidatedInput("Digite um número para calcular o módulo: ");

    cout << "O módulo de | " << formatNumber(num) << " | é " << formatNumber(mCalc(num)) << endl;

    returnOptions();
}

// MARK: Raiz N-ésima
double calcRaizN(double n, double i) {
    if (i == 0) throw invalid_argument("O índice da raiz não pode ser zero.");
    return pow(n, 1.0 / i);
}

void funcRaizN() {
    cout << "Calculando a Raiz N-ésima de um número\n" << endl;

    double n = getValidatedInput("Digite a base da Raiz: ");
    double i;
    while (true) {
        try {
            i = getValidatedInput("Digite o índice da Raiz: ");
            if (i == 0) throw invalid_argument("O índice da raiz não pode ser zero.");
            break;
        } catch (const invalid_argument& e) {
            handleError(e.what());
        }
    }

    try {
        double result = calcRaizN(n, i);
        cout << "A raiz " << formatNumber(i) << " de " << formatNumber(n) << " é " << formatNumber(result) << endl;
    } catch (const invalid_argument& e) {
        handleError(e.what());
    }

    returnOptions();
}
