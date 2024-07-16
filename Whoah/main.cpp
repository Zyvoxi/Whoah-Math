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
#include "math_functions.h"
#include "utility_functions.h"
    using namespace std;

// MARK: Forward Declarations
void options();
void handleOptionsChoice();

// MARK: Opções
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
        default:
            cout << "Opção inválida.\n";
            handleOptionsChoice();
            break;
    }
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
