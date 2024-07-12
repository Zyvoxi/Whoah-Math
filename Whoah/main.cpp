//
//  main.cpp
//  Whoah
//
//  Created by IV. on 11/07/24.
//

// MARK: Includes

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cmath>

// MARK: Utility Functions

bool isNumber(const std::string& str) {
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

void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    system("clear");
#else
    std::cout << "Não é possível limpar o console nesta plataforma.\n";
    return;
#endif
}

// MARK: Math Functions - Raiz de X - 1º

float calcrx(int a, int b) {
    return static_cast<float>(b / -1) / a;
}

void funcrx() {
    std::cout << "Descobrindo o valor de X\n" << std::endl;

    std::string la;
    std::cout << "Digite o valor de `a`: ";
    while (true) {
        std::getline(std::cin, la);
        if (isNumber(la)) {
            break;
        } else {
            std::cout << "Por Favor, digite um número válido: ";
        }
    }
    int a = std::stoi(la);

    std::string lb;
    std::cout << "Digite o valor de `b`: ";
    while (true) {
        std::getline(std::cin, lb);
        if (isNumber(lb)) {
            break;
        } else {
            std::cout << "Por Favor, digite um número válido: ";
        }
    }
    int b = std::stoi(lb);

    float res = calcrx(a, b);

#ifdef DEBUG
    std::cout << "\n";
#endif
    clearScreen();

    std::cout << "y = " << a << (b >= 0 ? "x + " : "x - ") << std::abs(b) <<
    std::endl << "0 = " << a << (b >= 0 ? "x + " : "x - ") << std::abs(b) <<
    std::endl << b / -1 << " = " << a << "x" <<
    std::endl << b / -1 << " / " << a << " = x" << std::endl;
    if (res == std::floor(res)) {
        std::cout << "x = " << static_cast<int>(res) << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(5) << "x = " << res << std::endl;
    }
    std::cout << std::endl;
}

// MARK: Math Functions - Raiz de X - 2º

double calcDelta(double a, double b, double c) {
    return (pow(b, 2)) - (4 * a * c);
}

void calcrx2(int a, int b, int delta, float& x1, float& x2) {
    x1 = (-b + sqrt(delta)) / (2.0 * a);
    x2 = (-b - sqrt(delta)) / (2.0 * a);
}

void funcrx2() {
    float x1, x2;

    std::string la;
    std::cout << "Digite o valor de `a`: ";
    while (true) {
        std::getline(std::cin, la);
        if (isNumber(la)) {
            break;
        } else {
            std::cout << "Por Favor, digite um número válido: ";
        }
    }
    int a = std::stoi(la);

    std::string lb;
    std::cout << "Digite o valor de `b`: ";
    while (true) {
        std::getline(std::cin, lb);
        if (isNumber(lb)) {
            break;
        } else {
            std::cout << "Por Favor, digite um número válido: ";
        }
    }
    int b = std::stoi(lb);

    std::string lc;
    std::cout << "Digite o valor de `c`: ";
    while (true) {
        std::getline(std::cin, lc);
        if (isNumber(lc)) {
            break;
        } else {
            std::cout << "Por Favor, digite um número válido: ";
        }
    }
    int c = std::stoi(lc);

    double delta = calcDelta(a, b, c);

#ifdef DEBUG
    std::cout << "\n";
#endif
    clearScreen();

    std::cout << "Δ = b² - 4ac" <<
    std::endl << "Δ - " << b << "²" << " - 4*" << a << "*" << c <<
    std::endl << "Δ = " << delta << std::endl;

    if (delta < 0) {
        std::cout << "Delta é negativo, então as raízes não fazem parte dos números reais, portanto não iremos encontrar elas.";
    } else {
        std::cout << std::setw(10) << "\n     -b  ±  √Δ " <<
        std::endl << std::setw(10) << "X = -----------" <<
        std::endl << std::setw(10) << "         2a    \n" << std::endl;
        
        std::cout << std::setw(10) << "\n     " << (b >= 0 ? "-" : " ") << (b >= 0 ? b : b/-1) << "  ±  √" << delta << " " <<
        std::endl << std::setw(10) << "X = -----------" << (delta >= 10 ? "---" : "") <<
        std::endl << std::setw(10) << "         2*" << a << "    \n" << std::endl;
        
        std::cout << std::setw(10) << "\n     " << (b >= 0 ? "-" : " ") << std::abs(b) << "  ±  ";
        if (delta == std::floor(delta)) {
            std::cout << static_cast<int>(sqrt(delta)) <<
            std::endl << std::setw(10) << "X = -----------" << (delta >= 10 ? "---" : "") <<
            std::endl << std::setw(10) << "         " << 2*a << "    \n" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(3) << sqrt(delta) <<
            std::endl << std::setw(10) << "X = -----------" << (delta >= 10 ? "---" : "") <<
            std::endl << std::setw(10) << "         " << 2*a << "    \n" << std::endl;
        }

        calcrx2(a, b, delta, x1, x2);

        std::cout << "X¹ = " << x1 <<
        std::endl << "x² = " << x2 << std::endl;
    }
    std::cout << std::endl;
}

// MARK: Options

void handleOptionsChoice() {
    int opt;

    std::cout << "\nEscolha uma opção: ";
    std::cin >> opt;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (opt) {
        case 1:
#ifdef DEBUG
            std::cout << "\n";
#endif
            clearScreen();
            funcrx();
            break;
        case 2:
#ifdef DEBUG
            std::cout << "\n";
#endif
            clearScreen();
            funcrx2();
            break;
        default:
            std::cout << "Por Favor, Escolha uma opção válida.";
            handleOptionsChoice();
            break;
    }
}

std::string nome;

void options() {
    std::cout << "Olá, " << nome << "!" <<
    std::endl << "Opções:" <<
    std::endl << "1) Calcular o valor de X em uma função de 1º grau" <<
    std::endl << "2) Calcular o valor de X em uma função de 2º grau" <<
    std::endl;

    handleOptionsChoice();
}

// MARK: Main

int main() {
    std::cout << "Digite seu nome: ";
    std::getline(std::cin, nome);

#ifdef DEBUG
    std::cout << "\n";
#endif
    clearScreen();
    options();

    return 0;
}
