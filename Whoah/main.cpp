//
//  main.cpp
//  Whoah
//
//  Created by IV. on 11/07/24.
//

#include <iostream>
#include <limits>
#include <string>
#include <locale>
#include "math_functions.hpp"
#include "math_tests.hpp"
#include "utility_functions.hpp"
    using namespace std;

// MARK: Declarações antecipadas
void options();
void handleOptionsChoice();

// MARK: Função das opções
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
         << endl << "6 - Calcular a média de uma lista de números"
         << endl << "7 - Calcular o módulo de um número"
         << endl << "8 - Calcular a Raiz N-ésima de um número"
         << endl << "9 - Calcular a derivada de um polinômio"
         << endl << "10 - Calcular a integral definida de um polinômio"
#if DEBUG
         << endl << "11 - Encontrar o valor máximo e mínimo de uma lista de números"
         << endl << "12 - Calcular o número de permutações possíveis de um conjunto de elementos"
         << endl << "13 - Calcular o número de combinações possíveis de um conjunto de elementos"
         << endl << "14 - Calcular a Média Geométrica de uma lista de números"
         << endl << "15 - Calcular a Média Harmônica de uma lista de números."
         << endl << "16 - Calcular a mediana de uma lista de números."
         << endl << "17 - Calcular o Desvio Padrão Amostral de uma lista de números."
         << endl << "18 - Calcular a Variância Amostral de um conjunto de números."
#endif
         << endl << "\n0 - Sair" << endl;

    handleOptionsChoice();
}

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
#if DEBUG
        case 3141:
            clearScreen();
            runMathTests();
            break;
#endif
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
        case 6:
            clearScreen();
            funcMedia();
            break;
        case 7:
            clearScreen();
            funcModulo();
            break;
        case 8:
            clearScreen();
            funcRaizN();
            break;
        case 9:
            clearScreen();
            funcDerivada();
            break;
        case 10:
            clearScreen();
            funcIntegralDefinida();
            break;
#if DEBUG
        case 11:
            clearScreen();
            funcMaxMin();
            break;
        case 12:
            clearScreen();
            funcPermutacao();
            break;
        case 13:
            clearScreen();
            funcCombinacao();
            break;
        case 14:
            clearScreen();
            funcMGeometrica();
            break;
        case 15:
            clearScreen();
            funcMHarmonica();
            break;
        case 16:
            clearScreen();
            funcMediana();
            break;
        case 17:
            clearScreen();
            funcDPAmostral();
            break;
        case 18:
            clearScreen();
            funcVariancia();
            break;
#endif
        default:
            cout << "Opção inválida.\n";
            handleOptionsChoice();
            break;
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

#if defined(_WIN32) || defined(_WIN64)
    system("chcp 65001");
#endif

    clearScreen();
    options();

    return 0;
}
