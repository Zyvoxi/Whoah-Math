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
#include <gmp.h>
#include <algorithm>
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
void calcFatorial(int n, mpz_t result) {
    if (n < 0) throw invalid_argument("Fatorial de número negativo não é definido.");

    mpz_set_ui(result, 1); // Inicializa result com 1

    for (int i = 2; i <= n; ++i) {
        mpz_mul_ui(result, result, i);
    }
}

void printFormulaFatorial(int n, const mpz_t result) {
    cout << n << "! = ";
    for (int i = 1; i <= n; ++i) {
        cout << i;
        if (i < n) {
            cout << " * ";
        }
    }
    cout << " = " << formatLargerNumber(result) << endl;
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
    cout << endl << "Derivada: ";
    for (size_t i = 0; i < derivada.size(); ++i) {
        cout << formatNumber(derivada[i]) << "x" << formatNumToSup((derivada.size() - 1 - i));
        if (i < derivada.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}

// MARK: Utilitarios - Integral Definida
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

// MARK: Utilitarios - MaxMin
pair<double, double> findMaxMin(const vector<double>& numbers) {
    if (numbers.empty()) {
        throw invalid_argument("A lista de números não pode estar vazia.");
    }

    auto result = minmax_element(numbers.begin(), numbers.end());
    return {*(result.first), *(result.second)};
}

void printMaxMin(const vector<double>& numbers, const pair<double, double>& maxMin) {
    cout << "Números: ";
    for (const double& num : numbers) {
        cout << formatNumber(num) << " ";
    }
    cout << endl << "Valor mínimo: " << formatNumber(maxMin.first)
         << endl << "Valor máximo: " << formatNumber(maxMin.second) << endl;
}

// MARK: Utilitarios - Permutação
void calcPermutacao(mpz_t resultado, int n, int k) {
    if (n < 0 || k < 0 || k > n) {
        throw invalid_argument("Os valores de n e k devem ser um numero inteiro positivo, e k deve ser menor ou igual a n.");
    }

    mpz_t temp;
    mpz_init(temp);

    mpz_set_ui(resultado, 1); // resultado = 1

    for (int i = 0; i < k; ++i) {
        mpz_set_ui(temp, n - i); // temp = n - i
        mpz_mul(resultado, resultado, temp); // resultado *= (n - i)
    }

    mpz_clear(temp);
}

void printFormulaPermutacao(int n, int k, const mpz_t resultado) {
    cout << "Número total de elementos (n): " << formatNumber(n)
         << endl << "Número de elementos selecionados (k): " << formatNumber(k)
         << endl << "Número de permutações (P(n, k)): " << formatLargerNumber(resultado) << endl;
}

// MARK: Utilitários - Combinação
long long calcCombinacao(int n, int k) {
    if (k > n || k < 0) {
        throw invalid_argument("k deve estar no intervalo [0, n].");
    }

    mpz_t fatorialN, fatorialK, fatorialN_k;
    mpz_init(fatorialN);
    mpz_init(fatorialK);
    mpz_init(fatorialN_k);

    try {
        calcFatorial(n, fatorialN);
        calcFatorial(k, fatorialK);
        calcFatorial(n - k, fatorialN_k);

        mpz_t numerador, denominador;
        mpz_init(numerador);
        mpz_init(denominador);

        mpz_mul(numerador, fatorialK, fatorialN_k);
        mpz_div(numerador, fatorialN, numerador);
        
        long long resultado = mpz_get_ui(numerador);
        
        mpz_clear(fatorialN);
        mpz_clear(fatorialK);
        mpz_clear(fatorialN_k);
        mpz_clear(numerador);
        mpz_clear(denominador);

        return resultado;
    } catch (const invalid_argument& e) {
        handleError(e.what());
        mpz_clear(fatorialN);
        mpz_clear(fatorialK);
        mpz_clear(fatorialN_k);
        return 0; // Valor de retorno em caso de erro
    }
}

void printFormulaCombinacao(int n, int k, long long resultado) {
    cout << "Número de combinações C(" << n << ", " << formatNumber(k) << ") = "
         << n << "!" << " / (" << k << "!" << " * (" << formatNumber(n) << " - " << formatNumber(k) << ")!)"
         << endl << "Resultado: " << formatNumber(resultado) << endl;
}

// MARK: Utilitários - Média Geométrica
double calcMGeometrica(const vector<double>& numeros) {
    if (numeros.empty()) {
        throw invalid_argument("O vetor está vazio");
    }

    double produto = 1.0;
    for (size_t i = 0; i < numeros.size(); ++i) {
        produto *= numeros[i];
    }

    return pow(produto, 1.0 / numeros.size());
}

void printFormulaMGeometrica(const vector<double>& numeros, double res) {
    double produto = 1.0;
    cout << formatNumToSup(numeros.size()) << "√";
    for (size_t i = 0; i < numeros.size(); ++i) {
        produto *= numeros[i];
        cout << formatNumber(numeros[i]);
        if (i < numeros.size() - 1) {
            cout << " * ";
        }
    }
    cout << endl << formatNumToSup(numeros.size()) << "√" << formatNumber(produto) << " = " << formatNumber(res) << endl;
}

// MARK: Utilitários - Média Harmônica
double calcMHarmonica(const vector<double>& numeros) {
    if (numeros.empty()) {
        throw invalid_argument("O vetor está vazio");
    } else if (find(numeros.begin(), numeros.end(), 0) != numeros.end()) {
        throw invalid_argument("O vetor contém um número zero");
    }

    double produto = 0;
    for (size_t i = 0; i < numeros.size(); ++i) {
        produto += 1/numeros[i];
    }

    return numeros.size()/produto;
}

void printFormulaMHarmonica(const vector<double>& numeros, double res) {
    cout << "H = ";
    double produto = 0;
    for (size_t i = 0; i < numeros.size(); ++i) {
        cout << "1/" << formatNumber(numeros[i]);
        if (i < numeros.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl << "H = ";
    for (size_t i = 0; i < numeros.size(); ++i) {
        produto = 1/numeros[i];
        cout << formatNumber(produto);
        if (i < numeros.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl << "H = " << formatNumber(res) << endl;
}

// MARK: Utilitários - Mediana
double calcMediana(const vector<double>& numeros) {
    if (numeros.empty()) {
        throw invalid_argument("O vetor está vazio");
    }

    vector<double> sorted_numeros = numeros;
    sort(sorted_numeros.begin(), sorted_numeros.end());

    size_t n = sorted_numeros.size();
    size_t mid = n / 2;

    if (isOdd(n)) {
        return sorted_numeros[mid];
    } else {
        return (sorted_numeros[mid - 1] + sorted_numeros[mid]) / 2.0;
    }
}

void printFormulaMediana(const vector<double>& numeros, double res) {
    vector<double> sorted_numeros = numeros;
    sort(sorted_numeros.begin(), sorted_numeros.end());

    cout << "Números ordenados: ";
    for (size_t i = 0; i < sorted_numeros.size(); ++i) {
        cout << formatNumber(sorted_numeros[i]) << " ";
    }
    cout << "= " << formatNumber(numeros.size()) << " observações (";

    if (isOdd(numeros.size())) {
        cout << "ímpar)" << endl;
        cout << "Mediana = (" << formatNumber(numeros.size()) << " + 1) / 2 = "
             << formatNumber((numeros.size() + 1) / 2.0) << "ᵃ observação = " << formatNumber(res) << endl;
    } else {
        cout << "par)"
             << endl << "Mediana = (" << formatNumber(numeros.size() / 2) << "ᵃ observação + "
             << formatNumber((numeros.size() / 2 + 1)) << "ᵃ observação) / 2 = ("
             << formatNumber(sorted_numeros[numeros.size() / 2 - 1]) << " + "
             << formatNumber(sorted_numeros[numeros.size() / 2]) << ") / 2 = " << formatNumber(res) << endl;
    }
}

// MARK: Utilitários - Desvio Padrão Amostral
double calcDPAmostral(const vector<double>& numeros) {
    if (numeros.empty()) {
        throw invalid_argument("O vetor está vazio");
    } else if (numeros.size() == 1) {
        throw invalid_argument("O vetor precisa conter mais de 1 número");
    }

    double res1 = 0, res2 = 0;
    for (size_t i = 0; i < numeros.size(); ++i) {
        res1 += numeros[i];
    }
    res1 /= numeros.size();
    for (size_t i = 0; i < numeros.size(); ++i) {
        res2 += pow(numeros[i] - res1, 2);
    }
    res2 *= 1.0 / (numeros.size() - 1.0);

    return sqrt(res2);
}

void printFormulaDPAmostral(const vector<double>& numeros, double res) {
    cout << "s = Desvio Padrão Amostral     x̅ = Média\n" << endl;

    cout << "x̅ = (";
    double res1 = 0, res2 = 0;
    for (size_t i = 0; i < numeros.size(); ++i) {
        res1 += numeros[i];
        cout << formatNumber(numeros[i]);
        if (i < numeros.size() - 1) {
            cout << " + ";
        } else {
            cout << ") / ";
        }
    }

    cout << formatNumber(numeros.size())
         << endl << "x̅ = " << formatNumber(res1) << " / " << formatNumber(numeros.size()) << endl;

    res1 /= numeros.size();

    cout << "x̅ = " << formatNumber(res1)
         << endl << "s = √1 / (" << formatNumber(numeros.size()) << " - 1) * ( ";
    for (size_t i = 0; i < numeros.size(); ++i) {
        res2 += pow(numeros[i] - res1, 2);
        cout << "(" << formatNumber(numeros[i]) << " - " << formatNumber(res1) << ")²";
        if (i < numeros.size() - 1) {
            cout << " + ";
        } else {
            cout << " )";
        }
    }

    cout << endl << "s = √1 / " << formatNumber(numeros.size() - 1) << " * (";
    for (size_t i = 0; i < numeros.size(); ++i) {
        cout << formatNumber(pow(numeros[i] - res1, 2));
        if (i < numeros.size() - 1) {
            cout << " + ";
        } else {
            cout << ")";
        }
    }

    cout << endl <<  "s = √1 / " << formatNumber(numeros.size() - 1) << " * " << formatNumber(res2)
         << endl << "s = √" << formatNumber((res2 *= 1.0 / (numeros.size() - 1.0)))
         << endl << "s = " << formatNumber(res)
         << endl;
}
