//
//  math_utils.hpp
//  Whoah
//
//  Created by IV. on 15/07/24.
//

#ifndef math_utils_hpp
#define math_utils_hpp

#include <vector>
#include <iostream>
#include <gmp.h>
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
 * @brief Calcula o fatorial de um número usando a biblioteca GMP.
 *
 * Esta função calcula o fatorial de um número inteiro não-negativo e armazena o resultado em um `mpz_t`.
 *
 * @param n Número inteiro não-negativo.
 * @param result Variável do tipo `mpz_t` onde o resultado do fatorial será armazenado.
 * @throw std::invalid_argument Se n for negativo.
 */
void calcFatorial(int n, mpz_t result);

/**
 * @brief Imprime a fórmula e o resultado do cálculo do fatorial de um número.
 *
 * Esta função imprime a fórmula detalhada do cálculo do fatorial e o resultado utilizando a biblioteca GMP.
 *
 * @param n Número cujo fatorial será calculado.
 * @param result Resultado do fatorial armazenado em uma variável do tipo `mpz_t`.
 */
void printFormulaFatorial(int n, const mpz_t result);

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
 * @brief Encontra o valor máximo e mínimo em uma lista de números.
 *
 * @param numbers Vetor de números.
 * @return std::pair<double, double> Par contendo o valor mínimo e máximo.
 * @throw std::invalid_argument Se o vetor estiver vazio.
 */
std::pair<double, double> findMaxMin(const std::vector<double>& numbers);

/**
 * @brief Imprime os valores máximo e mínimo de uma lista de números.
 *
 * @param numbers Vetor de números.
 * @param maxMin Par contendo o valor mínimo e máximo.
 */
void printMaxMin(const std::vector<double>& numbers, const std::pair<double, double>& maxMin);  

/**
 * @brief Calcula o número de permutações possíveis de um conjunto de elementos.
 *
 * @param n Número total de elementos.
 * @param k Número de elementos selecionados.
 * @throw std::invalid_argument Se n ou k forem negativos, ou se k for maior que n.
 */
void calcPermutacao(mpz_t resultado, int n, int k);

/**
 * @brief Imprime a fórmula e o cálculo do número de permutações possíveis.
 *
 * @param n Número total de elementos.
 * @param k Número de elementos selecionados.
 * @param resultado Número de permutações.
 */
void printFormulaPermutacao(int n, int k, const mpz_t resultado);

/**
 * @brief Calcula o número de combinações possíveis de um conjunto de elementos.
 *
 * Esta função calcula o número de combinações (ou combinações) C(n, k), onde n é o número total de itens e k é o número de itens a serem escolhidos.
 * Utiliza a fórmula: C(n, k) = n! / (k! * (n - k)!).
 *
 * @param n Número total de elementos.
 * @param k Número de elementos selecionados.
 * @return long long Número de combinações.
 * @throw std::invalid_argument Se k for maior que n ou se k for negativo.
 */
long long calcCombinacao(int n, int k);

/**
 * @brief Imprime a fórmula e o cálculo do número de combinações possíveis.
 *
 * Esta função exibe a fórmula matemática usada para calcular o número de combinações
 * e o resultado final.
 *
 * @param n Número total de elementos.
 * @param k Número de elementos selecionados.
 * @param resultado Número de combinações.
 */
void printFormulaCombinacao(int n, int k, long long resultado);

/**
 * @brief Calcula a média geométrica de uma lista de números.
 *
 * @param numeros Vetor de números.
 * @return double Média geométrica dos números.
 * @throws invalid_argument Se o vetor estiver vazio.
 */
double calcMGeometrica(const std::vector<double>& numeros);

/**
 * @brief Imprime a fórmula e o cálculo da média geométrica.
 *
 * Esta função exibe a fórmula matemática usada para cálcular a média geométrica
 * e o resultado final.
 *
 * @param numeros Vetor de números.
 * @param res Resultado da média geométrica.
 */
void printFormulaMGeometrica(const std::vector<double>& numeros, double res);

/**
 * @brief Calcula a média harmônica de uma lista de números.
 *
 * @param numeros Vetor de números.
 * @return double Média harmônica dos números.
 * @throws invalid_argument Se o vetor estiver vazio.
 */
double calcMHarmonica(const std::vector<double>& numeros);

/**
 * @brief Imprime a fórmula e o cálculo da média harmônica.
 *
 * Esta função exibe a fórmula matemática usada para cálcular a média harmônica
 * e o resultado final.
 *
 * @param numeros Vetor de números.
 * @param res Resultado da média geométrica.
 */
void printFormulaMHarmonica(const std::vector<double>& numeros, double res);

/**
 * @brief Calcula a mediana de um vetor de números.
 *
 * A mediana é o valor que separa a metade superior da metade inferior de um conjunto de dados ordenado.
 * Se o número de observações for ímpar, a mediana é o valor no meio do vetor ordenado.
 * Se o número de observações for par, a mediana é a média dos dois valores centrais.
 *
 * @param numeros Vetor de números (double) para o qual a mediana será calculada.
 * @return A mediana dos números no vetor.
 *
 * @note O vetor será ordenado internamente para calcular a mediana.
 * Se o vetor estiver vazio, o comportamento é indefinido.
 */
double calcMediana(const std::vector<double>& numeros);double calcMediana(const std::vector<double>& numeros);

/**
 * @brief Imprime a fórmula e o cálculo da mediana.
 *
 * Esta função exibe a fórmula matemática usada para cálcular a mediana
 * e o resultado final.
 *
 * @param numeros Vetor de números.
 * @param res Resultado da média geométrica.
 */
void printFormulaMediana(const std::vector<double>& numeros, double res);

#endif /* math_utils_hpp */
