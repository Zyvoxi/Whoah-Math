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
 * @brief Calcula a potência de um número.
 *
 * @param base Base da potência.
 * @param exp Expoente.
 * @return double Resultado da potência.
 */
double power(double base, int exp);

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
 * @brief Calcula a média de uma lista de números.
 *
 * @param nums Vetor de números.
 * @return double Média dos números.
 * @throw std::invalid_argument Se o vetor estiver vazio.
 */
double average(const std::vector<double>& nums);

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
 * @param num Base da raiz.
 * @param n Índice da raiz.
 * @return double Raiz n-ésima de num.
 * @throw std::invalid_argument Se n for zero.
 */
double calcRaizN(double num, int n);

#endif /* math_utils_hpp */
