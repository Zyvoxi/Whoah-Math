//
//  utility_functions.hpp
//  Whoah
//
//  Created by IV. on 15/07/24.
//

#ifndef utility_functions_hpp
#define utility_functions_hpp

#include <gmp.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <regex>
    using namespace std;

/**
 * @brief Verifica se uma string é um número no formato brasileiro.
 *
 * @param str String a ser verificada.
 * @return true Se a string for um número no formato brasileiro.
 * @return false Caso contrário.
 */
bool isBrazilianNumber(const string& str);

/**
 * @brief Verifica se uma string é um número.
 *
 * @param str String a ser verificada.
 * @return true Se a string for um número.
 * @return false Caso contrário.
 */
template <typename T>
bool isNumber(const T& str) {
    if (str.empty()) return false;

    size_t start = (str[0] == '-') ? 1 : 0;
    bool decimalPointFound = false;

    for (size_t i = start; i < str.length(); ++i) {
        if (str[i] == '.') {
            if (decimalPointFound) return false;
            decimalPointFound = true;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Verifica se um número é ímpar.
 *
 * Esta função template verifica se um número é ímpar.
 * Funciona para qualquer tipo que suporte a operação de módulo (%).
 *
 * @tparam T O tipo do número.
 * @param number O número a ser verificado.
 * @return true Se o número é ímpar.
 * @return false Se o número é par.
 */
template <typename T>
bool isOdd(T number) {
    return number % 2 != 0;
}

/**
 * @brief Converte um número do formato brasileiro para o formato americano.
 *
 * @param input Número no formato brasileiro.
 * @return string Número no formato americano.
 */
string convertBrazilianToAmerican(const string& input);

/**
 * @brief Solicita e valida a entrada do usuário como um número.
 *
 * @param prompt Mensagem de solicitação para o usuário.
 * @return double Número validado.
 */
double getValidatedInput(const string& prompt);

vector<double> processNumbersFromInput();

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
 * @return string Número formatado.
 */
string formatWithThousandsSeparator(double num);

/**
 * @brief Formata um número de acordo com o formato brasileiro.
 *
 * @param num Número a ser formatado.
 * @return string Número formatado.
 */
template <typename T>
string formatNumber(T num) {
    stringstream ss;

    if (num == floor(num)) {
        return formatWithThousandsSeparator(num);
    } else {
        ss << fixed << setprecision(3) << num;
        string result = ss.str();

        size_t pos = result.find('.');
        if (pos != string::npos) {
            result.replace(pos, 1, ",");
        }

        result.erase(result.find_last_not_of('0') + 1, string::npos);
        if (result.back() == ',') {
            result.pop_back();
        }

        if (num >= 1000 || num <= -1000) {
            double integerPart;
            modf(num, &integerPart);
            string integerPartFormatted = formatWithThousandsSeparator(integerPart);
            result.replace(0, pos, integerPartFormatted);
        }

        return result;
    }

    return ss.str();
}

/**
 * @brief Formata um número de acordo com o formato brasileiro.
 *
 * @param num Número a ser formatado.
 * @return string Número formatado.
 */
string formatLargerNumber(const mpz_t num);

/**
 * @brief Formata um número em subscrito.
 *
 * Esta função converte um número em uma string onde cada dígito é representado por seu correspondente em subscrito.
 * Por exemplo, o número 123.45 será convertido para "₁₂₃,₄₅".
 *
 * @param num O número a ser formatado.
 * @return string O número formatado em subscritos.
 */
template <typename T>
string formatNumToSub(T num) {
    string subs = "";
    string subsMap[] = {"₀", "₁", "₂", "₃", "₄", "₅", "₆", "₇", "₈", "₉"};

    ostringstream oss;
    oss << num;  // Usa o ostringstream para conversão
    string numStr = oss.str();

    for (char c : numStr) {
        if (c == '.') {
            subs += ",";  // Substitui o ponto decimal por vírgula
        } else {
            int d = c - '0';
            subs += subsMap[d];
        }
    }

    return subs;
}

/**
 * @brief Formata um número em superescrito.
 *
 * Esta função converte um número em uma string onde cada dígito é representado por seu correspondente em superescrito.
 * Por exemplo, o número 123.45 será convertido para "¹²³,⁴⁵".
 *
 * @param num O número a ser formatado.
 * @return string O número formatado em superescritos.
 */
template <typename T>
string formatNumToSup(T num) {
    string sub = "";
    string subMap[] = {"⁰", "¹", "²", "³", "⁴", "⁵", "⁶", "⁷", "⁸", "⁹"};

    ostringstream oss;
    oss << num;  // Usa o ostringstream para conversão
    string numStr = oss.str();

    for (char c : numStr) {
        if (c == '.') {
            sub += ",";  // Substitui o ponto decimal por vírgula
        } else {
            int d = c - '0';
            sub += subMap[d];
        }
    }

    return sub;
}

/**
 * @brief Trata erros e exibe mensagens detalhadas.
 *
 * @param error Mensagem de erro.
 */
void handleError(const string& error);

#endif /* utility_functions_hpp */
