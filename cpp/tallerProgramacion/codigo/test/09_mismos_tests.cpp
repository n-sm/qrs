#include "gtest/gtest.h"
#include "../src/taller.h"

TEST(mismos_tests, vacio) {
    int vacio[0] = {};
    EXPECT_EQ(true, mismos(vacio, vacio,0,0));
    int del1Al10[10] = {1,2,3,4,5,6,7,8,9,10};
    EXPECT_EQ(false, mismos(del1Al10, vacio,10,0));
    EXPECT_EQ(false, mismos(vacio, del1Al10,0,10));
}

TEST(mismos_tests, repetidos_y_desordenados) {
    int muchosRepetidos[15] = {3,3,3,5,5,5,-1,-1,0,0,0,27,59,59,-1000};
    int muchosRepetidosShuffle[15] = {0,3,5,-1000,5,0,-1,59,-1,3,0,27,3,59,5};
    EXPECT_EQ(true, mismos(muchosRepetidos, muchosRepetidosShuffle,15,15));
    EXPECT_EQ(true, mismos(muchosRepetidosShuffle, muchosRepetidos,15,15));
}

TEST(mismos_tests, sin_repetidos) {
    int del1Al10[10] = {1,2,3,4,5,6,7,8,9,10};
    int del10Al1[10] = {10,9,8,7,6,5,4,3,2,1};
    EXPECT_EQ(true, mismos(del1Al10, del10Al1,10,10));
    int horas[12] = {3,0,2,6,4,1,5,7,8,9,11,10};
    int reversoHoras[12] = {11,10,9,8,7,6,5,4,3,2,1,0};
    EXPECT_EQ(true, mismos(reversoHoras, horas,12,12));
    EXPECT_EQ(true, mismos(del1Al10, del1Al10,10,10));
}

TEST(mismos_tests, distintos) {
    int a[9] = {78, -1, -1, 10, -35, 89, 100, -100, 89};
    int b[9] = {78, -1, 10, -35, 89, 100, -100, 78, -35};
    EXPECT_EQ(false, mismos(a, b,9,9));
    EXPECT_EQ(false, mismos(b, a,9,9));
    int del11Al20[10] = {11,12,13,14,15,16,17,18,19,20};
    int del1Al10[10] = {1,2,3,4,5,6,7,8,9,10};
    EXPECT_EQ(false, mismos(del11Al20, del1Al10,10,10));
    EXPECT_EQ(false, mismos(a, del1Al10,9,10));
}

TEST(mismos_tests, subconjuntos) {
    int a[9] = {78, -1, -1, 10, -35, 89, 100, -100, 89};
    int incluyeAa[11] = {78, -1, -1, 10, -35, 89, 100, -100, 89, 501, -65};
    int del0Al10[11] = {0,1,2,3,4,5,6,7,8,9,10};
    int del1Al10[10] = {1,2,3,4,5,6,7,8,9,10};
    int distApariciones[10] = {78, -1, 10, -35, 89, 100, -100, 89, 501, -65};
    EXPECT_EQ(false, mismos(del0Al10, del1Al10,10,10));
    EXPECT_EQ(false, mismos(incluyeAa, a,11,9));
    EXPECT_EQ(false, mismos(distApariciones, incluyeAa,10,11));
    EXPECT_EQ(false, mismos(a, incluyeAa,9,11));
}



