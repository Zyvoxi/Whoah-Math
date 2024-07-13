//
//  main.cpp
//  Whoah
//
//  Created by IV. on 11/07/24.
//

// MARK: Includes
#include <iostream>
    using namespace std;
#include <string>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <limits>

// MARK: Forward Declarations
void options();

// MARK: Utility Functions
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

void clearScreen() {
#if DEBUG
    cout << "\n";
#else
    cout << "\033[2J\033[1;1H";
#endif
}

void returnOptions() {
    cout << "\nPressione Enter para Voltar ao Menu." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clearScreen();
    options();
}

double getValidatedInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);
        if (isNumber(input)) {
            istringstream(input) >> value;
            break;
        }
        cout << "Por Favor, digite um número válido.\n";
    }
    return value;
}

// MARK: Math Functions - Raiz de X - 1º
float calcrx(double a, double b) {
    return static_cast<float>(-b / a);
}

void printFormulaRX(double a, double b, float res) {
    cout << "y = " << a << (b >= 0 ? "x + " : "x - ") << abs(b) << endl;
    cout << "0 = " << a << (b >= 0 ? "x + " : "x - ") << abs(b) << endl;
    cout << -b << " = " << a << "x" << endl;
    cout << -b << " / " << a << " = x" << endl;
    cout << fixed << setprecision(5) << "x = " << res << endl;
}

void funcrx() {
    cout << "Descobrindo o valor de X em uma função de 1º grau.\n" << endl;

    double a;
    while (true) {
        a = getValidatedInput("Digite o valor de `a`: ");
        if (a != 0) break;
        cout << "Erro: `a` não pode ser 0.\n";
    }
    double b = getValidatedInput("Digite o valor de `b`: ");

    float res = calcrx(a, b);

    clearScreen();
    printFormulaRX(a, b, res);

    returnOptions();
}

// MARK: Math Functions - Raiz de X - 2º
void calcDelta(double a, double b, double c, double& delta) {
    delta = (pow(b, 2)) - (4 * a * c);
}

void calcrx2(double a, double b, double delta, double& x1, double& x2) {
    if (delta >= 0) {
        x1 = (-b + sqrt(delta)) / (2.0 * a);
        x2 = (-b - sqrt(delta)) / (2.0 * a);
    }
}

void printDelta(double a, double b, double c, double delta) {
    cout << "Δ = b² - 4ac"
         << endl << "Δ = " << b << "² - 4*" << a << "*" << c
         << endl << "Δ = " << delta << endl;
}

void printFormulaRX2(double b, double delta, double a) {
    cout << setw(10) << "\n     -b  ±  √Δ "
         << endl << setw(10) << "X = -----------"
         << endl << setw(10) << "         2a    \n" << endl;

    cout << setw(10) << "\n     " << (b >= 0 ? "-" : " ") << abs(b) << "  ±  √" << (delta == floor(delta) ? to_string(static_cast<int>(delta)) : to_string(delta))
         << endl << setw(10) << "X = -----------" << (delta >= 10 ? "---" : "")
         << endl << setw(10) << "         2*" << (a == floor(a) ? to_string(static_cast<int>(a)) : to_string(a)) << "    \n" << endl;

    cout << setw(10) << "\n     " << (b >= 0 ? "-" : " ") << abs(b) << "  ±  " << (sqrt(delta) == floor(sqrt(delta)) ? to_string(static_cast<int>(sqrt(delta))) : to_string(sqrt(delta)))
         << endl << setw(10) << "X = -----------" << (delta >= 10 ? "---" : "")
         << endl << setw(10) << "         " << (2 * a == floor(2 * a) ? to_string(static_cast<int>(2 * a)) : to_string(2 * a)) << "    \n" << endl;
}

void funcrx2() {
    cout << "Descobrindo o valor de X em uma função de 2º grau.\n" << endl;
    
    double a;
    while (true) {
        a = getValidatedInput("Digite o valor de `a`: ");
        if (a != 0) break;
        cout << "Erro: `a` não pode ser 0.\n";
    }
    double b = getValidatedInput("Digite o valor de `b`: ");
    double c = getValidatedInput("Digite o valor de `c`: ");

    double x1, x2, delta;
    calcDelta(a, b, c, delta);
    calcrx2(a, b, delta, x1, x2);

    clearScreen();
    printDelta(a, b, c, delta);

    if (delta < 0) {
        cout << "Delta é negativo, então as raízes não fazem parte dos números reais, portanto não iremos encontrar elas.\n";
    } else {
        printFormulaRX2(b, delta, a);
        cout << "X¹ = " << x1
             << endl << "X² = " << x2
             << endl;
    }
    returnOptions();
}

// MARK: Options
void handleOptionsChoice() {
    int opt;

    cout << "Escolha uma opção: ";
    while (true) {
        string optInput;
        getline(cin, optInput);
        if (isNumber(optInput)) {
            opt = stoi(optInput);
            break;
        } else {
            cout << "Opção inválida.\nEscolha uma opção: ";
        }
    }

    switch(opt) {
        case 0:
            cout << "\nVocê escolheu sair\n" << endl;
            exit(0);
            break;
        case 1:
            clearScreen();
            funcrx();
            break;
        case 2:
            clearScreen();
            funcrx2();
            break;
        default:
            cout << "Opção inválida.\n";
            handleOptionsChoice();
            break;
    }
}

void options() {
#if DEBUG
    cout << "!-Versão de DEBUG-!\n" << endl;
#endif

    cout << "Escolha uma das opções para realizar o cálculo de suas raízes!\n"
         << endl << "1 - Calcular o valor de X em uma função de 1º grau"
         << endl << "2 - Calcular o valor de X em uma função de 2º grau"
         << endl << "\n0 - Sair"
         << endl;

    handleOptionsChoice();

}

// MARK: Main
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

#if defined(_WIN32) || defined(_WIN64)
    system("chcp 65001");
#endif

    clearScreen();
    options();

    return 0;
}
