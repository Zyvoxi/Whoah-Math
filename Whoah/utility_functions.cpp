//
//  utility_functions.cpp
//  Whoah
//
//  Created by IV. on 15/07/24.
//

#include "utility_functions.hpp"
#include "main.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <regex>
    using namespace std;

// MARK: Validador dos Inputs
bool isBrazilianNumber(const string& str) {
    regex pattern(R"(^-?(\d{1,3}(\.\d{3})*|\d+)(,\d{1,3})?$)");
    return regex_match(str, pattern);
}

string convertBrazilianToAmerican(const string& input) {
    string formatted = input;

    formatted.erase(remove(formatted.begin(), formatted.end(), '.'), formatted.end());

    size_t commaPos = formatted.find(',');
    if (commaPos != string::npos) {
        formatted.replace(commaPos, 1, ".");
    }

    return formatted;
}

double getValidatedInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);
        try {
            if (isBrazilianNumber(input)) {
                string c = convertBrazilianToAmerican(input);
                if (isNumber(c)) {
                    istringstream(c) >> value;
                    break;
                }
            }
            throw invalid_argument("Por favor, digite um número válido.");
        } catch (const invalid_argument& e) {
            handleError(e.what());
        }
    }
    return value;
}

vector<double> processNumbersFromInput() {
    cout << "Insira os números separados por espaços: ";
    string input;
    getline(cin, input);
    istringstream stream(input);
    vector<double> numbers;
    string token;
    while (stream >> token) {
        if (isBrazilianNumber(token)) {
            string c = convertBrazilianToAmerican(token);
            double n;
            if (isNumber(c)) {
                istringstream(c) >> n;
                numbers.push_back(n);
            } else {
                handleError("Número inválido ignorado: " + token);
            }
        } else {
            handleError("Número inválido ignorado: " + token);
        }
    }

    return numbers;
}

// MARK: Limpador
void clearScreen() {
#if DEBUG
    cout << "\n\n";
#else
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    system("clear");
#else
    cout << "\033[2J\033[1;1H";
#endif
#endif
}

// MARK: Retornador das Opções
void returnOptions() {
    cout << "\n⏎ Pressione Enter para Voltar ao Menu." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clearScreen();
    options();
}

// MARK: Formatador de Números
class CustomNumPunct : public numpunct<char> {
protected:
    virtual char do_thousands_sep() const override {
        return '.';
    }

    virtual string do_grouping() const override {
        return "\3";
    }
};

string formatWithThousandsSeparator(double num) {
    stringstream ss;
    ss.imbue(locale(locale(), new CustomNumPunct()));
    ss << fixed << setprecision(0) << num;
    return ss.str();
}

string formatLargerNumber(const mpz_t num) {
    // Converte o número grande para string
    string numStr = mpz_get_str(nullptr, 10, num);
    string result(numStr);

    // Remove espaços e outros caracteres indesejados
    result.erase(0, result.find_first_not_of(' '));
    result.erase(result.find_last_not_of(' ') + 1);

    // Adiciona separadores de milhares
    string formattedNum;
    unsigned long long length = result.length();
    int start = length % 3;

    // Adiciona a primeira parte, se existir
    if (start > 0) {
        formattedNum.append(result.substr(0, start));
    }

    // Adiciona os grupos de três dígitos separados por pontos
    for (int i = start; i < length; i += 3) {
        if (i > 0) formattedNum.append(".");
        formattedNum.append(result.substr(i, 3));
    }

    return formattedNum;
}

// MARK: Error
void handleError(const string& error) {
    cout << "Erro: " << error << endl;
}
