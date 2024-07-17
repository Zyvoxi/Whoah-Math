//
//  math_functions.hpp
//  Whoah
//
//  Created by IV. on 15/07/24.
//

#ifndef math_functions_hpp
#define math_functions_hpp

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
 * @brief Função principal para encontrar o valor de X em uma equação de primeiro grau.
 */
void funcRX();

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
 * @brief Função principal para encontrar as raízes de uma equação de segundo grau.
 */
void funcRX2();

/**
 * @brief Calcula o fatorial de um número.
 *
 * @param n Número inteiro não-negativo.
 * @return unsigned long long Fatorial de n.
 * @throw std::invalid_argument Se n for negativo.
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
 * @brief Função principal para calcular o fatorial de um número.
 */
void funcFatorial();

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
void printFormulaPotencia(double base, int exponent, double result);

/**
 * @brief Função principal para calcular a potência de um número.
 */
void funcPotencia();

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
 * @brief Função principal para calcular o logaritmo de um número.
 */
void funcLogaritmo();

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
 * @brief Função principal para calcular a média de uma lista de números.
 */
void funcMedia();

/**
 * @brief Calcula o módulo de um número.
 *
 * @param num Número.
 * @return double Módulo de num.
 */
double mCalc(double num);

/**
 * @brief Função principal para calcular o módulo de um número.
 */
void funcModulo();

/**
 * @brief Calcula a raiz n-ésima de um número.
 *
 * @param n Base da raiz.
 * @param i Índice da raiz.
 * @return double Raiz n-ésima de n.
 * @throw std::invalid_argument Se i for zero.
 */
double calcRaizN(double n, double i);

/**
 * @brief Imprime a fórmula e o cálculo da raiz N-ésima de um número.
 *
 * @param base Base da raiz.
 * @param index Índice da raiz.
 * @param result Resultado da raiz N-ésima.
 */
void printFormulaRaizN(double base, double index, double result);

/**
 * @brief Função principal para calcular a raiz n-ésima de um número.
 */
void funcRaizN();

/**
 * @brief Executa os testes unitários para as funções matemáticas.
 */
void runMathTests();

#endif /* math_functions_hpp */
