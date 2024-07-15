//
//  utility_functions.cpp
//  Whoah
//
//  Created by IV. on 15/07/24.
//

#include "utility_functions.h"
#include "main.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <regex>

using namespace std;

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

void returnOptions() {
    cout << "\nPressione Enter para Voltar ao Menu." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clearScreen();
    options();
}

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

void handleError(const string& error) {
    cout << "Erro: " << error << endl;
    cout << "Sugestão: Verifique se os valores inseridos estão corretos e tente novamente." << endl;
}
