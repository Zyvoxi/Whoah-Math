//
//  main.cpp
//  Whoah
//
//  Created by IV. on 11/07/24.
//

// MARK: Includes
#include <string>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <limits>
#include <vector>
#include <iostream>
#include <regex>
#include <locale>
using namespace std;

// MARK: Forward Declarations
void options();

// MARK: Utility Functions
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

    // Remove os pontos (separadores de milhar)
    formatted.erase(remove(formatted.begin(), formatted.end(), '.'), formatted.end());
    
    // Troca a vírgula (separador decimal) por um ponto
    size_t commaPos = formatted.find(',');
    if (commaPos != string::npos) {
        formatted.replace(commaPos, 1, ".");
    }

    return formatted; // Converte para double
}

double getValidatedInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);
        if (isBrazilianNumber(input)) {
            string c;
            c = convertBrazilianToAmerican(input);
            if (isNumber(c)) {
                istringstream(c) >> value;
                break;
            }
        }
        cout << "Por favor, digite um número válido.\n";
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
        // Começa com 3 casas decimais
        ss << fixed << setprecision(3) << num;
        string result = ss.str();

        // Substitui o ponto decimal por vírgula
        size_t pos = result.find('.');
        if (pos != string::npos) {
            result.replace(pos, 1, ",");
        }

        // Remove zeros finais e a vírgula decimal se não houver casas decimais
        result.erase(result.find_last_not_of('0') + 1, string::npos);
        if (result.back() == ',') {
            result.pop_back(); // Remove a vírgula decimal se for o último caractere
        }

        // Se for um número grande, formatar com separadores de milhar
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

// MARK: Math Functions - Raiz de X - 1º
void calcRX(double a, double b, float& x) {
    x = static_cast<float>(-b / a);
}

void printFormulaRX(double a, double b, float x) {
    cout << "y = " << formatNumber(a) << (b >= 0 ? "x + " : "x - ") << formatNumber(abs(b))
         << endl << "0 = " << formatNumber(a) << (b >= 0 ? "x + " : "x - ") << formatNumber(abs(b))
         << endl << formatNumber(-b) << " = " << formatNumber(a) << "x"
         << endl << formatNumber(-b) << " / " << formatNumber(a) << " = x"
         << endl << "x = " << formatNumber(x) << endl;
}

void funcRX() {
    cout << "Descobrindo o valor de X em uma função de 1º grau.\n" << endl;

    float x;

    double a;
    while (true) {
        a = getValidatedInput("Digite o valor de `a`: ");
        if (a != 0) break;
        cout << "Erro: `a` não pode ser 0.\n";
    }
    double b = getValidatedInput("Digite o valor de `b`: ");

    calcRX(a, b, x);

    clearScreen();
    printFormulaRX(a, b, x);

    returnOptions();
}

// MARK: Math Functions - Raiz de X - 2º
void calcDelta(double a, double b, double c, double& delta) {
    delta = (pow(b, 2)) - (4 * a * c);
}

void calcRX2(double a, double b, double delta, double& x1, double& x2) {
    if (delta >= 0) {
        x1 = (-b + sqrt(delta)) / (2.0 * a);
        x2 = (-b - sqrt(delta)) / (2.0 * a);
    }
}

void printDelta(double a, double b, double c, double delta) {
    cout << "Δ = b² - 4ac"
         << endl << "Δ = " << formatNumber(b) << "² - 4*" << formatNumber(a) << "*" << formatNumber(c)
         << endl << "Δ = " << formatNumber(delta) << endl;
}

void printFormulaRX2(double b, double delta, double a) {
    cout << setw(10) << "\n     -b  ±  √Δ "
         << endl << setw(10) << "X = -----------"
         << endl << setw(10) << "         2a    \n" << endl;

    cout << setw(10) << "\n     " << (b >= 0 ? "-" : " ") << formatNumber(abs(b)) << "  ±  " << formatNumber(delta)
         << endl << setw(10) << "X = -----------" << (delta >= 10 ? "---" : "")
         << endl << setw(10) << "         2*" << formatNumber(a) << "    \n" << endl;

    cout << setw(10) << "\n     " << (b >= 0 ? "-" : " ") << formatNumber(abs(b)) << "  ±  " << formatNumber(sqrt(delta))
         << endl << setw(10) << "X = -----------" << (delta >= 10 ? "---" : "")
         << endl << setw(10) << "         " << formatNumber(2 * a) << "    \n" << endl;
}

void funcRX2() {
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
    calcRX2(a, b, delta, x1, x2);

    clearScreen();
    printDelta(a, b, c, delta);

    if (delta < 0) {
        cout << "\nDelta é negativo, então as raízes não fazem parte dos números reais, portanto não iremos encontrar elas.\n";
    } else {
        printFormulaRX2(b, delta, a);
        cout << "X¹ = " << formatNumber(x1)
             << endl << "X² = " << formatNumber(x2) << endl;
    }
    returnOptions();
}

// MARK: Math Functions - Fatorial
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void funcFatorial() {
    cout << "Calculando o fatorial de um número.\n" << endl;

    double n;
    while (true) {
        n = getValidatedInput("Digite um número inteiro não-negativo: ");
        if (n == floor(n) && n >= 0) break;
        cout << "Erro: Por favor digite um numero inteiro não-negativo.\n";
    }

    try {
        unsigned long long result = factorial(n);
        cout << "O fatorial de " << formatNumber(n) << " é " << formatNumber(result) << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    returnOptions();
}

// MARK: Math Functions - Potência
double power(double base, int exponent) {
    return pow(base, exponent);
}

void funcPotencia() {
    cout << "Calculando a potência de um número.\n" << endl;

    double base = getValidatedInput("Digite a base: ");
    double exponent = getValidatedInput("Digite o expoente: ");

    double result = pow(base, exponent);
    cout << formatNumber(base) << " elevado a " << formatNumber(exponent) << " é " << formatNumber(result) << endl;

    returnOptions();
}

// MARK: Math Functions - Logaritmo
double logarithm(double value, double base) {
    return log(value) / log(base);
}

void funcLogaritmo() {
    cout << "Calculando o logaritmo de um número.\n" << endl;

    double value = getValidatedInput("Digite o valor: ");
    double base = getValidatedInput("Digite a base: ");

    if (value > 0 && base > 0 && base != 1) {
        double result = logarithm(value, base);
        cout << "O logaritmo de " << formatNumber(value) << " na base " << formatNumber(base) << " é " << formatNumber(result) << endl;
    } else {
        cout << "Erro: O valor e a base devem ser positivos e a base deve ser diferente de 1.\n";
    }

    returnOptions();
}

// MARK: Math Functions - Média
#if DEBUG
double average(const vector<double>& numbers) {
    double sum = 0;
    for (double number : numbers) {
        sum += number;
    }
    return sum / numbers.size();
}

void funcMedia() {
    cout << "Calculando a média de uma lista de números.\n" << endl;

    cout << "Digite os números separados por espaço (pressione Enter para finalizar): ";
    string input;
    getline(cin, input);
    istringstream stream(input);

    vector<double> numbers;
    double number;
    while (stream >> number) {
        numbers.push_back(number);
    }

    if (!numbers.empty()) {
        double result = average(numbers);
        cout << "A média é " << formatNumber(result) << endl;
    } else {
        cout << "Erro: Nenhum número foi fornecido.\n";
    }

    returnOptions();
}
#endif

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
            funcRX();
            break;
        case 2:
            clearScreen();
            funcRX2();
            break;
        case 3:
            clearScreen();
            funcFatorial();
            break;
        case 4:
            clearScreen();
            funcPotencia();
            break;
        case 5:
            clearScreen();
            funcLogaritmo();
            break;
#if DEBUG
        case 6:
            clearScreen();
            funcMedia();
            break;
#endif
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
         << endl << "3 - Calcular o fatorial de um número"
         << endl << "4 - Calcular a potência de um número"
         << endl << "5 - Calcular o logaritmo de um número"
#if DEBUG
         << endl << "6 - Calcular a média de uma lista de números"
#endif
         << endl << "\n0 - Sair" << endl;

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
