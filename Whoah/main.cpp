//
//  main.cpp
//  Whoah
//
//  Created by IV. on 11/07/24.
//

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cmath>

bool is_number(const std::string& str) {
    if (str.empty()) return false;

    size_t start = 0;
    if (str[0] == '-') {
        if (str.length() == 1) return false;
        start = 1;
    }

    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

float soma(int a, int b) {
    return static_cast<float>(b / -1) / a;
}

int main() {
    std::cout << "Descobrindo o valor de X" << std::endl;

    std::string la;
    std::cout << "Digite o valor de `a`: ";
    while (true) {
        std::getline(std::cin, la);
        if (is_number(la)) {
            break;
        } else {
            std::cout << "Por Favor, digite um numero valido: ";
        }
    }
    int a = std::stoi(la);

    std::string lb;
    std::cout << "Digite o valor de `b`: ";
    while (true) {
        std::getline(std::cin, lb);
        if (is_number(lb)) {
            break;
        } else {
            std::cout << "Por Favor, digite um numero valido: ";
        }
    }
    int b = std::stoi(lb);

    float res = soma(a, b);

    std::cout << "y = " << a << (b >= 0 ? "x + " : "x - ") << (b < 0 ? b / -1 : b) << std::endl;
    std::cout << "0 = " << a << (b >= 0 ? "x + " : "x - ") << (b < 0 ? b / -1 : b) << std::endl;
    std::cout << b / -1 << " = " << a << "x" << std::endl;
    std::cout << b / -1 << " / " << a << " = x" << std::endl;
    if (res == std::floor(res)) {
        std::cout << "x = " << static_cast<int>(res) << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(5) << "x = " << res << std::endl;
    }

    return 0;
}
