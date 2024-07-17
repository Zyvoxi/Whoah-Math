//
//  math_utils.cpp
//  Whoah
//
//  Created by IV. on 17/07/24.
//

#include "math_utils.hpp"
#include "utility_functions.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <vector>
    using namespace std;

// MARK: Utilitarios - Raiz de X - 1º
double calcRX(double a, double b) {
    if (a == 0) throw invalid_argument("O coeficiente 'a' não pode ser zero.");
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

// MARK: Utilitarios - Raiz de X - 2º
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
    cout << setw(10) << "\\n     -b  ±  √Δ "
         << endl << setw(10) << "X = ------------"
         << endl << setw(10) << "         2a    \\n" << endl;

    cout << setw(10) << "\\n     " << (b >= 0 ? "-" : " ") << formatNumber(fabs(b)) << "  ±  √" << formatNumber(delta)
         << endl << setw(10) << "     ------------"
         << endl << setw(10) << "         2 * " << formatNumber(a) << "\\n" << endl;
}

// MARK: Utilitarios - Fatorial
unsigned long long calcFatorial(int n) {
    if (n < 0) throw invalid_argument("Fatorial de número negativo não é definido.");
    if (n > 65) throw overflow_error("Valor muito grande para calcular o fatorial sem estouro.");
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void printFormulaFatorial(int n, unsigned long long result) {
    cout << formatNumber(n) << "! = ";
    for (int i = 1; i <= n; ++i) {
        cout << formatNumber(i);
        if (i < n) {
            cout << " * ";
        }
    }
    cout << " = " << formatNumber(result) << endl;
}

// MARK: Utilitarios - Exponenciação
double power(double base, int exp) {
    if (exp == 0) return 1;
    if (base == 0) return 0;
    double result = 1;
    for (int i = 0; i < abs(exp); ++i) {
        result *= base;
    }
    if (exp < 0) return 1 / result;
    return result;
}

// MARK: Utilitarios - Logaritmo
double calcLog(double value, double base) {
    if (value <= 0 || base <= 0 || base == 1) throw invalid_argument("Valor e base devem ser maiores que zero e base não pode ser 1.");
    return log(value) / log(base);
}

// MARK: Utilitarios - Média
double average(const vector<double>& nums) {
    if (nums.empty()) throw invalid_argument("O vetor não pode estar vazio.");
    double sum = 0;
    for (double num : nums) {
        sum += num;
    }
    return sum / nums.size();
}

// MARK: Utilitarios - Módulo
double mCalc(double num) {
    return abs(num);
}

// MARK: Utilitarios - Raiz Enésima
double calcRaizN(double num, int n) {
    if (n <= 0) throw invalid_argument("O índice deve ser maior que zero.");
    return pow(num, 1.0 / n);
}
