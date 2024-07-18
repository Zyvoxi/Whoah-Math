//
//  math_utils.hpp
//  Whoah
//
//  Created by IV. on 15/07/24.
//

#ifndef math_utils_hpp
#define math_utils_hpp

#include <vector>
#include <stdexcept>

/**
 * @brief Calcula o valor de X em uma equação de primeiro grau.
 *
 * @param a Coeficiente da variável X.
 * @param b Coeficiente constante.
 * @return double Valor de X.
 * @throw std::invalid_argument Se a for zero.
 */
double calcRX(double a, double b);

/**
 * @brief Imprime a fórmula e o cálculo para encontrar X em uma equação de primeiro grau.
 *
 * @param a Coeficiente da variável X.
 * @param b Coeficiente constante.
 * @param x Valor de X.
 */
void printFormulaRX(double a, double b, double x);

/**
 * @brief Calcula o delta (discriminante) de uma equação de segundo grau.
 *
 * @param a Coeficiente quadrático.
 * @param b Coeficiente linear.
 * @param c Coeficiente constante.
 * @return double Valor de delta.
 */
double calcDelta(double a, double b, double c);

/**
 * @brief Calcula as raízes de uma equação de segundo grau.
 *
 * @param a Coeficiente quadrático.
 * @param b Coeficiente linear.
 * @param delta Valor do discriminante.
 * @param x1 Referência para armazenar a primeira raiz.
 * @param x2 Referência para armazenar a segunda raiz.
 */
void calcRX2(double a, double b, double delta, double& x1, double& x2);

/**
 * @brief Imprime o cálculo do delta para uma equação de segundo grau.
 *
 * @param a Coeficiente quadrático.
 * @param b Coeficiente linear.
 * @param c Coeficiente constante.
 * @param delta Valor do discriminante.
 */
void printDelta(double a, double b, double c, double delta);

/**
 * @brief Imprime a fórmula e o cálculo das raízes de uma equação de segundo grau.
 *
 * @param b Coeficiente linear.
 * @param delta Valor do discriminante.
 * @param a Coeficiente quadrático.
 */
void printFormulaRX2(double b, double delta, double a);

/**
 * @brief Calcula o fatorial de um número.
 *
 * @param n Número inteiro não-negativo.
 * @return unsigned long long Fatorial de n.
 * @throw std::invalid_argument Se n for negativo.
 * @throw std::overflow_error Se n for maior que 65.
 */
unsigned long long calcFatorial(int n);

/**
 * @brief Imprime a fórmula e o cálculo do fatorial de um número.
 *
 * @param n Número cujo fatorial será calculado.
 * @param result Resultado do fatorial.
 */
void printFormulaFatorial(int n, unsigned long long result);

/**
 * @brief Calcula a potência de um número.
 *
 * @param base Base da potência.
 * @param exponent Expoente.
 * @return double Resultado da potência.
 */
double power(double base, double exponent);

/**
 * @brief Imprime a fórmula e o cálculo da potência de um número.
 *
 * @param base Base da potência.
 * @param exponent Expoente.
 * @param result Resultado da potência.
 */
void printFormulaPotencia(double base, double exponent, double result);

/**
 * @brief Calcula o logaritmo de um número em uma base especificada.
 *
 * @param value Valor cujo logaritmo será calculado.
 * @param base Base do logaritmo.
 * @return double Logaritmo de value na base base.
 * @throw std::invalid_argument Se value ou base forem menores ou iguais a zero, ou se base for igual a 1.
 */
double calcLog(double value, double base);

/**
 * @brief Imprime a fórmula e o cálculo do logaritmo de um número.
 *
 * @param value Valor cujo logaritmo será calculado.
 * @param base Base do logaritmo.
 * @param result Resultado do logaritmo.
 */
void printFormulaLogaritmo(double value, double base, double result);

/**
 * @brief Calcula a média de uma lista de números.
 *
 * @param numbers Vetor de números.
 * @return double Média dos números.
 * @throw std::invalid_argument Se o vetor estiver vazio.
 */
double average(const std::vector<double>& numbers);

/**
 * @brief Imprime a fórmula e o cálculo da média de uma lista de números.
 *
 * @param numbers Vetor de números.
 * @param result Resultado da média.
 */
void printFormulaMedia(const std::vector<double>& numbers, double result);

/**
 * @brief Calcula o módulo de um número.
 *
 * @param num Número.
 * @return double Módulo de num.
 */
double mCalc(double num);

/**
 * @brief Calcula a raiz n-ésima de um número.
 *
 * @param base Base da raiz.
 * @param index Índice da raiz.
 * @return double Raiz n-ésima de base.
 * @throw std::invalid_argument Se o índice for zero.
 */
double calcRaizN(double base, double index);

/**
 * @brief Imprime a fórmula e o cálculo da raiz N-ésima de um número.
 *
 * @param base Base da raiz.
 * @param index Índice da raiz.
 * @param result Resultado da raiz N-ésima.
 */
void printFormulaRaizN(double base, double index, double result);

/**
 * @brief Calcula a derivada de uma função polinomial.
 *
 * @param coeficientes Vetor de coeficientes do polinômio.
 * @return std::vector<double> Vetor de coeficientes da derivada.
 */
std::vector<double> calcDerivada(const std::vector<double>& coeficientes);

/**
 * @brief Imprime a fórmula e o cálculo da derivada de uma função polinomial.
 *
 * @param coeficientes Vetor de coeficientes do polinômio.
 * @param derivada Vetor de coeficientes da derivada.
 */
void printFormulaDerivada(const std::vector<double>& coeficientes, const std::vector<double>& derivada);

/**
 * @brief Calcula a integral definida de uma função polinomial.
 *
 * @param coeficientes Vetor de coeficientes do polinômio.
 * @param a Limite inferior de integração.
 * @param b Limite superior de integração.
 * @return double Valor da integral definida.
 */
double calcIntegralDefinida(const std::vector<double>& coeficientes, double a, double b);

/**
 * @brief Imprime a fórmula e o cálculo da integral definida de uma função polinomial.
 *
 * @param coeficientes Vetor de coeficientes do polinômio.
 * @param a Limite inferior de integração.
 * @param b Limite superior de integração.
 * @param resultado Valor da integral definida.
 */
void printFormulaIntegralDefinida(const std::vector<double>& coeficientes, double a, double b, double resultado);

/**
 * @brief Executa os testes unitários para as funções matemáticas.
 */
void runMathTests();

#endif /* math_utils_hpp */
