//
//  utility_functions.h
//  Whoah
//
//  Created by IV. on 15/07/24.
//

#ifndef utility_functions_h
#define utility_functions_h

#include <string>

/**
 * @brief Verifica se uma string é um número no formato brasileiro.
 *
 * @param str String a ser verificada.
 * @return true Se a string for um número no formato brasileiro.
 * @return false Caso contrário.
 */
bool isBrazilianNumber(const std::string& str);

/**
 * @brief Verifica se uma string é um número.
 *
 * @param str String a ser verificada.
 * @return true Se a string for um número.
 * @return false Caso contrário.
 */
bool isNumber(const std::string& str);

/**
 * @brief Converte um número do formato brasileiro para o formato americano.
 *
 * @param input Número no formato brasileiro.
 * @return std::string Número no formato americano.
 */
std::string convertBrazilianToAmerican(const std::string& input);

/**
 * @brief Solicita e valida a entrada do usuário como um número.
 *
 * @param prompt Mensagem de solicitação para o usuário.
 * @return double Número validado.
 */
double getValidatedInput(const std::string& prompt);

/**
 * @brief Limpa a tela do console.
 */
void clearScreen();

/**
 * @brief Retorna ao menu de opções.
 */
void returnOptions();

/**
 * @brief Formata um número com separadores de milhar.
 *
 * @param num Número a ser formatado.
 * @return std::string Número formatado.
 */
std::string formatWithThousandsSeparator(double num);

/**
 * @brief Formata um número de acordo com o formato brasileiro.
 *
 * @param num Número a ser formatado.
 * @return std::string Número formatado.
 */
std::string formatNumber(double num);

/**
 * @brief Trata erros e exibe mensagens detalhadas.
 *
 * @param error Mensagem de erro.
 */
void handleError(const std::string& error);

#endif // utility_functions_h
