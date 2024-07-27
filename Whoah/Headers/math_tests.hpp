//
//  math_tests.hpp
//  Whoah
//
//  Created by IV. on 18/07/24.
//

#ifndef math_tests_hpp
#define math_tests_hpp

#include <string>

/**
 * @brief Executa todos os testes unitários para funções matemáticas.
 */
void runMathTests();

/**
 * @brief Verifica se a condição é verdadeira, caso contrário, incrementa o contador de falhas e exibe uma mensagem.
 * @param condition Condição a ser verificada.
 * @param testName Nome do teste.
 * @param failureCount Contador de falhas.
 */
void checkTest(bool condition, const std::string& testName, int& failureCount);

/**
 * @brief Executa testes unitários para a função calcRX.
 */
void runCalcRXTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função calcDelta.
 */
void runCalcDeltaTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função calcRX2.
 */
void runCalcRX2Tests(int& failureCount);

/**
 * @brief Executa testes unitários para a função calcFatorial.
 */
void runCalcFatorialTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função power.
 */
void runPowerTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função calcLog.
 */
void runCalcLogTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função average.
 */
void runAverageTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função mCalc.
 */
void runMCalcTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função calcRaizN.
 */
void runCalcRaizNTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função calcDerivada.
 */
void runCalcDerivadaTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função calcIntegralDefinida.
 */
void runCalcIntegralDefinidaTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função findMaxMin.
 */
void runFindMaxMinTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função calcPermutacao.
 */
void runCalcPermutacaoTests(int& failureCount);

/**
 * @brief Executa testes unitários para a função calcCombinacao.
 */
void runCalcCombinacaoTests(int& failureCount);

/**
 * @brief Executa testes unitário para a função calcMGeometrica.
 */
void runCalcMGeometricaTests(int& failureCount);

/**
 * @brief Executa testes unitário para a função calcMHarmonica.
 */
void runCalcMHarmonicaTests(int& failureCount);

/**
 * @brief Executa testes unitário para a função calcMediana.
 */
void runCalcMedianaTests(int& failureCount);

/**
 * @brief Executa testes unitário para a função calcDPAmostral.
 */
void runCalcDPAmostralTests(int& failureCount);

/**
 * @brief Executa testes unitário para a função calcVariancia.
 */
void runCalcVarianciaTests(int& failureCount);

#endif /* math_tests_hpp */
