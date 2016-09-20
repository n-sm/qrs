#include <iostream>
#include <cmath>
#include "gtest/gtest.h"
#include "../src/taller.h"

bool esBuenaAproximacion(const float calc, const float orig, const float precision){
    float absErr = abs(calc-orig);
    if(calc == 0 || orig == 0){
        return absErr < precision;
    }else{
        return (absErr / abs(calc)) < precision;
    }
}

TEST(desvioEstandar_tests, std_buenas_aproximaciones) {
    float notas[11] = {20,15,26,32,18,28,35,14,26,22,17};
    float norm[7] = {-0.5, 0.98, 1.2, -1.0, -0.345, 0.478, 1.230};
    float todosCero[5] = {0,0,0,0,0};
    float otraData[8] = {9.87, 9.60, 9.56, 8.01, 7.99, 9.87, 7.67, 9.14};
    float precision = 0.01;
    EXPECT_EQ(true, esBuenaAproximacion(desvioEstandar(notas, 11), 6.6332, precision));
    EXPECT_EQ(true, esBuenaAproximacion(desvioEstandar(todosCero, 5), 0, precision));
    EXPECT_EQ(true, esBuenaAproximacion(desvioEstandar(norm, 7), 0.83790, precision));
    EXPECT_EQ(true, esBuenaAproximacion(desvioEstandar(otraData, 8), 0.86354, precision));
}