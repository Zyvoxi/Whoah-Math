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
#include <cassert>
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

// MARK: Utilitarios - Potencia
double power(double base, double exponent) {
    return pow(base, exponent);
}

void printFormulaPotencia(double base, double exponent, double result) {
    cout << formatNumber(base) << formatNumToSup(exponent) << " = ";
    
    if (exponent == 0) {
        cout << "1 (Qualquer número elevado a 0 é 1)" << endl;
    } else if (exponent == 1) {
        cout << formatNumber(base) << " (Qualquer número elevado a 1 é o próprio número)" << endl;
    } else if (exponent == floor(exponent)) {
        cout << formatNumber(base);
        for (int i = 1; i < static_cast<int>(exponent); ++i) {
            cout << " * " << formatNumber(base);
        }
        cout << " = " << formatNumber(result) << endl;
    } else {
        cout << formatNumber(result) << endl;
    }
}

// MARK: Utilitarios - Logaritmo
double calcLog(double value, double base) {
    if (value <= 0 || base <= 0 || base == 1) throw invalid_argument("O valor e a base devem ser positivos e a base deve ser diferente de 1.");
    return log(value) / log(base);
}

void printFormulaLogaritmo(double value, double base, double result) {
    cout << "log" << formatNumToSub(base) << "(" << formatNumber(value) << ") = " << formatNumber(result)
         << endl << "Usando a mudança de base: log_b(x) = log(x) / log(b)"
         << endl << "log" << formatNumToSub(base) << "(" << formatNumber(value) << ") = log(" << formatNumber(value) << ") / log(" << formatNumber(base) << ")"
         << endl << "log" << formatNumToSub(base) << "(" << formatNumber(value) << ") = " << formatNumber(log(value)) << " / " << formatNumber(log(base)) << " = " << formatNumber(result) << endl;
}

// MARK: Utilitarios - Média
double average(const vector<double>& numbers) {
    if (numbers.empty()) throw invalid_argument("A lista de números não pode estar vazia.");
    double sum = 0;
    for (double number : numbers) {
        sum += number;
    }
    return sum / numbers.size();
}

void printFormulaMedia(const vector<double>& numbers, double result) {
    cout << "Média = (";
    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << formatNumber(numbers[i]);
        if (i < numbers.size() - 1) {
            cout << " + ";
        }
    }
    cout << ") / " << formatNumber(numbers.size()) << endl;

    double sum = 0;
    for (size_t i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }
    cout << "Média = " << formatNumber(sum) << " / " << formatNumber(numbers.size()) << " = " << formatNumber(result) << endl;
}

// MARK: Utilitarios - Módulo
double mCalc(double num) {
    return fabs(num);
}

// MARK: Utilitarios - Raiz N-ésima
double calcRaizN(double base, double index) {
    if (index == 0) throw invalid_argument("O índice da raiz não pode ser zero.");
    return pow(base, 1.0 / index);
}

void printFormulaRaizN(double base, double index, double result) {
    cout << formatNumToSup(index) << "√" << formatNumber(base) << " = " << formatNumber(result) << endl;
}

// MARK: Utilitarios - Derivada
vector<double> calcDerivada(const vector<double>& coeficientes) {
    vector<double> derivada;
    unsigned long grau = coeficientes.size() - 1;
    for (int i = 0; i < grau; ++i) {
        derivada.push_back(coeficientes[i] * (grau - i));
    }
    return derivada;
}

void printFormulaDerivada(const vector<double>& coeficientes, const vector<double>& derivada) {
    cout << "Polinômio: ";
    for (size_t i = 0; i < coeficientes.size(); ++i) {
        cout << formatNumber(coeficientes[i]) << "x" << formatNumToSup((coeficientes.size() - 1 - i));
        if (i < coeficientes.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;

    cout << "Derivada: ";
    for (size_t i = 0; i < derivada.size(); ++i) {
        cout << formatNumber(derivada[i]) << "x" << formatNumToSup((derivada.size() - 1 - i));
        if (i < derivada.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}

double calcIntegralDefinida(const vector<double>& coeficientes, double a, double b) {
    if (a > b) {
        throw invalid_argument("O limite inferior não pode ser maior que o limite superior.");
    }
    double integralA = 0;
    double integralB = 0;
    unsigned long grau = coeficientes.size() - 1;
    for (size_t i = 0; i < coeficientes.size(); ++i) {
        integralA += coeficientes[i] * pow(a, grau - i + 1) / (grau - i + 1);
        integralB += coeficientes[i] * pow(b, grau - i + 1) / (grau - i + 1);
    }

    return integralB - integralA;
}

void printFormulaIntegralDefinida(const vector<double>& coeficientes, double a, double b, double resultado) {
    cout << "Polinômio: ";
    for (size_t i = 0; i < coeficientes.size(); ++i) {
        cout << formatNumber(coeficientes[i]) << "x" << formatNumToSup((coeficientes.size() - 1 - i));
        if (i < coeficientes.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;

    cout << "Integral definida de " << formatNumber(a) << " a " << formatNumber(b) << ": ";
    for (size_t i = 0; i < coeficientes.size(); ++i) {
        cout << "(" << formatNumber(coeficientes[i]) << "x" << formatNumToSup((coeficientes.size() - 1 - i) + 1) << "/" << formatNumber((coeficientes.size() - 1 - i) + 1) << ")";
        if (i < coeficientes.size() - 1) {
            cout << " + ";
        }
    }
    cout << " de " << formatNumber(a) << " a " << formatNumber(b) << " = " << formatNumber(resultado) << endl;
}
