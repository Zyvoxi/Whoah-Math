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

bool isNumber(const string& str) {
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
    cout << "\nPressione Enter para Voltar ao Menu." << endl;
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

string formatNumber(double num) {
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

string formatLargerNumber(const mpz_t num) {
    // Converte o número grande para string
    char *numStr = mpz_get_str(nullptr, 10, num);
    string result(numStr);
    free(numStr); // Libera a memória alocada pela mpz_get_str
    
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

string formatNumToSub(double num) {
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

string formatNumToSup(double num) {
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

// MARK: Error
void handleError(const string& error) {
    cout << "Erro: " << error << endl;
}
