//
//  math_tests.cpp
//  Whoah
//
//  Created by IV. on 18/07/24.
//

#include "math_tests.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "utility_functions.hpp"
#include "math_utils.hpp"
    using namespace std;

void checkTest(bool condition, const string& testName, int& failureCount) {
    if (!condition) {
        cerr << "Teste falhou: " << testName << endl;
        ++failureCount;
    }
}

void runCalcRXTests(int& failureCount) {
    checkTest(calcRX(2, -4) == 2, "calcRX(2, -4) == 2", failureCount);
    checkTest(calcRX(1, -1) == 1, "calcRX(1, -1) == 1", failureCount);
    checkTest(calcRX(10, 0) == 0, "calcRX(10, 0) == 0", failureCount);
    checkTest(calcRX(-5, 10) == 2, "calcRX(-5, 10) == 2", failureCount);

    try {
        calcRX(0, 1);
        checkTest(false, "calcRX(0, 1) deveria lançar exceção", failureCount);
    } catch (const invalid_argument& e) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
}

void runCalcDeltaTests(int& failureCount) {
    checkTest(calcDelta(1, -3, 2) == 1, "calcDelta(1, -3, 2) == 1", failureCount);
    checkTest(calcDelta(1, 2, 1) == 0, "calcDelta(1, 2, 1) == 0", failureCount);
    checkTest(calcDelta(1, 0, -4) == 16, "calcDelta(1, 0, -4) == 16", failureCount);
    checkTest(calcDelta(1, 0, 0) == 0, "calcDelta(1, 0, 0) == 0", failureCount);
}

void runCalcRX2Tests(int& failureCount) {
    double x1, x2;
    calcRX2(1, -3, 1, x1, x2);
    checkTest(x1 == 2 && x2 == 1, "calcRX2(1, -3, 1, x1, x2)", failureCount);
    calcRX2(10, 20, 1600, x1, x2);
    checkTest(x1 == 1 && x2 == -3, "calcRX2(10, 20, 1600, x1, x2)", failureCount);
}

void runCalcFatorialTests(int& failureCount) {
    checkTest(calcFatorial(0) == 1, "calcFatorial(0) == 1", failureCount);
    checkTest(calcFatorial(5) == 120, "calcFatorial(5) == 120", failureCount);

    try {
        calcFatorial(-1);
        checkTest(false, "calcFatorial(-1) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }

    try {
        calcFatorial(66);
        checkTest(false, "calcFatorial(66) deveria lançar exceção", failureCount);
    } catch (const overflow_error&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
}

void runPowerTests(int& failureCount) {
    checkTest(power(2, 3) == 8, "power(2, 3) == 8", failureCount);
    checkTest(power(5, 0) == 1, "power(5, 0) == 1", failureCount);
    checkTest(power(0, 0) == 1, "power(0, 0) == 1", failureCount);
    checkTest(power(0, 5) == 0, "power(0, 5) == 0", failureCount);
    checkTest(power(-2, 2) == 4, "power(-2, 2) == 4", failureCount);
    checkTest(power(-2, 3) == -8, "power(-2, 3) == -8", failureCount);
}

void runCalcLogTests(int& failureCount) {
    checkTest(calcLog(8, 2) == 3, "calcLog(8, 2) == 3", failureCount);
    checkTest(calcLog(1, 10) == 0, "calcLog(1, 10) == 0", failureCount);

    try {
        calcLog(-1, 10);
        checkTest(false, "calcLog(-1, 10) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }

    try {
        calcLog(10, -1);
        checkTest(false, "calcLog(10, -1) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }

    try {
        calcLog(10, 1);
        checkTest(false, "calcLog(10, 1) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
}

void runAverageTests(int& failureCount) {
    vector<double> nums1 = {1, 2, 3, 4, 5};
    checkTest(average(nums1) == 3, "average({1, 2, 3, 4, 5}) == 3", failureCount);

    vector<double> nums2 = {10, 20, 30};
    checkTest(average(nums2) == 20, "average({10, 20, 30}) == 20", failureCount);

    try {
        vector<double> empty;
        average(empty);
        checkTest(false, "average(empty) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
}

void runMCalcTests(int& failureCount) {
    checkTest(mCalc(-5) == 5, "mCalc(-5) == 5", failureCount);
    checkTest(mCalc(5) == 5, "mCalc(5) == 5", failureCount);
    checkTest(mCalc(0) == 0, "mCalc(0) == 0", failureCount);
}

void runCalcRaizNTests(int& failureCount) {
    checkTest(calcRaizN(27, 3) == 3, "calcRaizN(27, 3) == 3", failureCount);
    checkTest(calcRaizN(16, 4) == 2, "calcRaizN(16, 4) == 2", failureCount);

    try {
        calcRaizN(27, 0);
        checkTest(false, "calcRaizN(27, 0) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
}

void runCalcDerivadaTests(int& failureCount) {
    vector<double> coef = {3, 2, 1}; // 3x^2 + 2x + 1
    vector<double> deriv = calcDerivada(coef);
    checkTest(deriv.size() == 2, "calcDerivada({3, 2, 1}) deve ter tamanho 2", failureCount);
    checkTest(deriv[0] == 6, "coeficiente 0 deve ser 6", failureCount);
    checkTest(deriv[1] == 2, "coeficiente 1 deve ser 2", failureCount);

    coef = {5, 0, -3}; // 5x^2 - 3
    deriv = calcDerivada(coef);
    checkTest(deriv.size() == 2, "calcDerivada({5, 0, -3}) deve ter tamanho 2", failureCount);
    checkTest(deriv[0] == 10, "coeficiente 0 deve ser 10", failureCount);
    checkTest(deriv[1] == 0, "coeficiente 1 deve ser 0", failureCount);

    coef = {4, -2}; // 4x - 2
    deriv = calcDerivada(coef);
    checkTest(deriv.size() == 1, "calcDerivada({4, -2}) deve ter tamanho 1", failureCount);
    checkTest(deriv[0] == 4, "coeficiente 0 deve ser 4", failureCount);

    coef = {7}; // 7
    deriv = calcDerivada(coef);
    checkTest(deriv.size() == 0, "calcDerivada({7}) deve ter tamanho 0", failureCount);
}

void runCalcIntegralDefinidaTests(int& failureCount) {
    std::vector<double> coef = {3, 2, 1}; // 3x^2 + 2x + 1
    double integral = calcIntegralDefinida(coef, 0, 1); // Integral de 0 a 1
    checkTest(std::abs(integral - 3) < 0.0001, "calcIntegralDefinida({3, 2, 1}, 0, 1) deve ser aproximadamente 3", failureCount);

    coef = {1, 0, -1}; // x^2 - 1
    integral = calcIntegralDefinida(coef, -1, 1); // Integral de -1 a 1
    checkTest(std::abs(integral - (-1.3333)) < 0.0001, "calcIntegralDefinida({1, 0, -1}, -1, 1) deve ser aproximadamente -1.3333", failureCount);

    coef = {2, -1}; // 2x - 1
    integral = calcIntegralDefinida(coef, 0, 2); // Integral de 0 a 2
    checkTest(std::abs(integral - 2) < 0.0001, "calcIntegralDefinida({2, -1}, 0, 2) deve ser aproximadamente 2", failureCount);

    coef = {5}; // 5
    integral = calcIntegralDefinida(coef, 1, 3); // Integral de 1 a 3
    checkTest(std::abs(integral - 10) < 0.0001, "calcIntegralDefinida({5}, 1, 3) deve ser aproximadamente 10", failureCount);
}

void runMathTests() {
    cout << "Executando testes unitários...\n";
    int failureCount = 0;

    runCalcRXTests(failureCount);
    runCalcDeltaTests(failureCount);
    runCalcRX2Tests(failureCount);
    runCalcFatorialTests(failureCount);
    runPowerTests(failureCount);
    runCalcLogTests(failureCount);
    runAverageTests(failureCount);
    runMCalcTests(failureCount);
    runCalcRaizNTests(failureCount);
    runCalcDerivadaTests(failureCount);
    runCalcIntegralDefinidaTests(failureCount);

    if (failureCount == 0) {
        cout << "Todos os testes foram executados com sucesso!\n";
    } else {
        cout << failureCount << " testes falharam.\n";
    }

    returnOptions();
}
