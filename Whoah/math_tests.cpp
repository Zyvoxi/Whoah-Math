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
    // Teste para fatorial de 0
    {
        mpz_t result;
        mpz_init(result);
        calcFatorial(0, result);
        checkTest(mpz_cmp_ui(result, 1) == 0, "calcFatorial(0) == 1", failureCount);
        mpz_clear(result);
    }

    // Teste para fatorial de 5
    {
        mpz_t result;
        mpz_init(result);
        calcFatorial(5, result);
        mpz_t expected;
        mpz_init_set_ui(expected, 120); // 5! = 120
        checkTest(mpz_cmp(result, expected) == 0, "calcFatorial(5) == 120", failureCount);
        mpz_clear(result);
        mpz_clear(expected);
    }

    // Teste para exceção em fatorial de número negativo
    try {
        mpz_t result;
        mpz_init(result);
        calcFatorial(-1, result);
        checkTest(false, "calcFatorial(-1) deveria lançar exceção", failureCount);
        mpz_clear(result);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }

    // Teste para fatorial de número muito grande (exceção removida, pois a GMP lida com números grandes)
    {
        mpz_t result;
        mpz_init(result);
        try {
            calcFatorial(66, result);
            checkTest(true, "calcFatorial(66) não deveria lançar exceção", failureCount);
        } catch (const overflow_error&) {
            checkTest(false, "calcFatorial(66) não deveria lançar exceção", failureCount);
        }
        mpz_clear(result);
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
    vector<double> coef = {3, 2, 1}; // 3x^2 + 2x + 1
    double integral = calcIntegralDefinida(coef, 0, 1); // Integral de 0 a 1
    checkTest(abs(integral - 3) < 0.0001, "calcIntegralDefinida({3, 2, 1}, 0, 1) deve ser aproximadamente 3", failureCount);

    coef = {1, 0, -1}; // x^2 - 1
    integral = calcIntegralDefinida(coef, -1, 1); // Integral de -1 a 1
    checkTest(abs(integral - (-1.3333)) < 0.0001, "calcIntegralDefinida({1, 0, -1}, -1, 1) deve ser aproximadamente -1.3333", failureCount);

    coef = {2, -1}; // 2x - 1
    integral = calcIntegralDefinida(coef, 0, 2); // Integral de 0 a 2
    checkTest(abs(integral - 2) < 0.0001, "calcIntegralDefinida({2, -1}, 0, 2) deve ser aproximadamente 2", failureCount);

    coef = {5}; // 5
    integral = calcIntegralDefinida(coef, 1, 3); // Integral de 1 a 3
    checkTest(abs(integral - 10) < 0.0001, "calcIntegralDefinida({5}, 1, 3) deve ser aproximadamente 10", failureCount);
}

void runFindMaxMinTests(int& failureCount) {
    vector<double> nums = {1, 2, 3, 4, 5};
    auto maxMin = findMaxMin(nums);
    checkTest(maxMin.first == 1, "findMaxMin({1, 2, 3, 4, 5}) valor mínimo deve ser 1", failureCount);
    checkTest(maxMin.second == 5, "findMaxMin({1, 2, 3, 4, 5}) valor máximo deve ser 5", failureCount);

    nums = {-10, 0, 10};
    maxMin = findMaxMin(nums);
    checkTest(maxMin.first == -10, "findMaxMin({-10, 0, 10}) valor mínimo deve ser -10", failureCount);
    checkTest(maxMin.second == 10, "findMaxMin({-10, 0, 10}) valor máximo deve ser 10", failureCount);

    nums = {7, 7, 7};
    maxMin = findMaxMin(nums);
    checkTest(maxMin.first == 7, "findMaxMin({7, 7, 7}) valor mínimo deve ser 7", failureCount);
    checkTest(maxMin.second == 7, "findMaxMin({7, 7, 7}) valor máximo deve ser 7", failureCount);

    nums = {42};
    maxMin = findMaxMin(nums);
    checkTest(maxMin.first == 42, "findMaxMin({42}) valor mínimo deve ser 42", failureCount);
    checkTest(maxMin.second == 42, "findMaxMin({42}) valor máximo deve ser 42", failureCount);

    try {
        vector<double> empty;
        findMaxMin(empty);
        checkTest(false, "findMaxMin(empty) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
}

void runCalcPermutacaoTests(int& failureCount) {
    mpz_t resultado;
    mpz_init(resultado);
    mpz_t expected;

    // Teste para permutação com valores pequenos
    calcPermutacao(resultado, 10, 2);
    mpz_init_set_ui(expected, 90); // Esperado: 10! / (10-2)! = 90
    checkTest(mpz_cmp(resultado, expected) == 0, "calcPermutacao(10, 2) == 90", failureCount);
    mpz_clear(expected);

    // Teste para permutação com valores grandes
    calcPermutacao(resultado, 5, 3);
    mpz_init_set_ui(expected, 60); // Esperado: 5! / (5-3)! = 60
    checkTest(mpz_cmp(resultado, expected) == 0, "calcPermutacao(5, 3) == 60", failureCount);
    mpz_clear(expected);

    // Teste para permutação onde k > n
    try {
        calcPermutacao(resultado, 3, 5);
        checkTest(false, "calcPermutacao(3, 5) deveria lançar exceção", failureCount);
    } catch (const invalid_argument& e) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }

    // Teste para permutação de 0 elementos
    calcPermutacao(resultado, 0, 0);
    mpz_init_set_ui(expected, 1); // Esperado: 0! / (0-0)! = 1
    checkTest(mpz_cmp(resultado, expected) == 0, "calcPermutacao(0, 0) == 1", failureCount);
    mpz_clear(expected);

    mpz_clear(resultado);
}

void runCalcCombinacaoTests(int& failureCount) {
    checkTest(calcCombinacao(10, 5) == 252, "calcCombinacao(10, 5) == 252", failureCount);
    checkTest(calcCombinacao(5, 2) == 10, "calcCombinacao(5, 2) == 10", failureCount);
    checkTest(calcCombinacao(6, 0) == 1, "calcCombinacao(6, 0) == 1", failureCount);
    checkTest(calcCombinacao(6, 6) == 1, "calcCombinacao(6, 6) == 1", failureCount);

    try {
        calcCombinacao(5, 6);
        checkTest(false, "calcCombinacao(5, 6) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }

    try {
        calcCombinacao(5, -1);
        checkTest(false, "calcCombinacao(5, -1) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
}

void runCalcMGeometricaTests(int& failureCount) {
    // Teste para média geométrica de uma lista de números positivos
    vector<double> nums1 = {1, 2, 3, 4, 5};
    checkTest(abs(calcMGeometrica(nums1) - 2.60517) < 0.0001, "calcMGeometrica({1, 2, 3, 4, 5})", failureCount);

    // Teste para média geométrica com números diferentes
    vector<double> nums2 = {10, 20, 30};
    checkTest(abs(calcMGeometrica(nums2) - 18.17) < 0.01, "calcMGeometrica({10, 20, 30})", failureCount);

    // Teste para média geométrica com todos os números iguais
    vector<double> nums3 = {7, 7, 7};
    checkTest(abs(calcMGeometrica(nums3) - 7) < 0.0001, "calcMGeometrica({7, 7, 7})", failureCount);

    // Teste para média geométrica de um único número
    vector<double> nums4 = {42};
    checkTest(abs(calcMGeometrica(nums4) - 42) < 0.0001, "calcMGeometrica({42})", failureCount);

    // Teste para exceção em vetor vazio
    try {
        vector<double> empty;
        calcMGeometrica(empty);
        checkTest(false, "calcMGeometrica(empty) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
}

void runCalcMHarmonicaTests(int& failureCount) {
    // Teste para uma lista de números positivos
    vector<double> nums1 = {1, 2, 3, 4, 5};
    checkTest(abs(calcMHarmonica(nums1) - 2.18978) < 0.0001,
              "calcMediaHarmonica({1, 2, 3, 4, 5})",
              failureCount);

    // Teste para uma lista com valores muito variados
    vector<double> nums2 = {10, 20, 30};
    checkTest(abs(calcMHarmonica(nums2) - 16.6667) < 0.0001,
              "calcMediaHarmonica({10, 20, 30})",
              failureCount);

    // Teste para uma lista com todos os números iguais
    vector<double> nums3 = {7, 7, 7};
    checkTest(abs(calcMHarmonica(nums3) - 7) < 0.0001,
              "calcMediaHarmonica({7, 7, 7})",
              failureCount);

    // Teste para uma lista com um único número
    vector<double> nums4 = {42};
    checkTest(abs(calcMHarmonica(nums4) - 42) < 0.0001,
              "calcMediaHarmonica({42})",
              failureCount);

    // Teste para uma lista contendo zeros (deve lançar exceção)
    try {
        vector<double> nums5 = {0, 1, 2, 3};
        calcMHarmonica(nums5);
        checkTest(false, "calcMediaHarmonica({0, 1, 2, 3}) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }

    // Teste para uma lista vazia (deve lançar exceção)
    try {
        vector<double> empty;
        calcMHarmonica(empty);
        checkTest(false, "calcMediaHarmonica(empty) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
}

void runCalcMedianaTests(int& failureCount) {
    // Teste para uma lista de números ímpares
    vector<double> nums1 = {1, 3, 5, 7, 9};
    checkTest(calcMediana(nums1) == 5, "calcMediana({1, 3, 5, 7, 9}) == 5", failureCount);

    // Teste para uma lista de números pares
    vector<double> nums2 = {1, 3, 5, 7, 9, 11};
    checkTest(calcMediana(nums2) == 6, "calcMediana({1, 3, 5, 7, 9, 11}) == 6", failureCount);

    // Teste para uma lista de números negativos
    vector<double> nums3 = {-5, -3, -1, 1, 3};
    checkTest(calcMediana(nums3) == -1, "calcMediana({-5, -3, -1, 1, 3}) == -1", failureCount);

    // Teste para uma lista de números com valores iguais
    vector<double> nums4 = {2, 2, 2, 2};
    checkTest(calcMediana(nums4) == 2, "calcMediana({2, 2, 2, 2}) == 2", failureCount);

    // Teste para uma lista com um único número
    vector<double> nums5 = {7};
    checkTest(calcMediana(nums5) == 7, "calcMediana({7}) == 7", failureCount);

    // Teste para uma lista vazia (deve lançar exceção)
    try {
        vector<double> empty;
        calcMediana(empty);
        checkTest(false, "calcMediana(empty) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
}

void runCalcDPAmostralTests(int& failureCount) {
    vector<double> nums1 = {1, 2, 3, 4, 5};
    checkTest(abs(calcDPAmostral(nums1) - 1.58114) < 0.0001, "calcDPAmostral({1, 2, 3, 4, 5})", failureCount);

    vector<double> nums2 = {10, 20, 30, 40, 50};
    checkTest(abs(calcDPAmostral(nums2) - 15.8114) < 0.0001, "calcDPAmostral({10, 20, 30, 40, 50})", failureCount);

    vector<double> nums3 = {7, 7, 7, 7, 7};
    checkTest(abs(calcDPAmostral(nums3) - 0) < 0.0001, "calcDPAmostral({7, 7, 7, 7, 7})", failureCount);

    vector<double> nums4 = {4, 8, 6, 5, 3, 2, 8, 6, 4, 2};
    checkTest(abs(calcDPAmostral(nums4) - 2.14) < 0.01, "calcDPAmostral({4, 8, 6, 5, 3, 2, 8, 6, 4, 2})", failureCount);

    try {
        vector<double> empty;
        calcDPAmostral(empty);
        checkTest(false, "calcDPAmostral(empty) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }

    try {
        vector<double> nums5 = {1};
        calcDPAmostral(nums5);
        checkTest(false, "calcDPAmostral({1}) deveria lançar exceção", failureCount);
    } catch (const invalid_argument&) {
        checkTest(true, "Exceção esperada lançada", failureCount);
    }
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
    runFindMaxMinTests(failureCount);
    runCalcPermutacaoTests(failureCount);
    runCalcCombinacaoTests(failureCount);
    runCalcMGeometricaTests(failureCount);
    runCalcMHarmonicaTests(failureCount);
    runCalcMedianaTests(failureCount);
    runCalcDPAmostralTests(failureCount);

    if (failureCount == 0) {
        cout << "Todos os testes foram executados com sucesso!\n";
    } else {
        cout << failureCount << " testes falharam.\n";
    }

    returnOptions();
}
