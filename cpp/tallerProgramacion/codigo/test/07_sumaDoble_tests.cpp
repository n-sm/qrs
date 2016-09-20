#include "gtest/gtest.h"
#include "../src/taller.h"

TEST(sumaDoble_tests, impares) {
    int impares[10] = {1,3,5,7,9,11,23,33,99,101};
    EXPECT_EQ(0, sumaDoble(impares, 10));
}

TEST(sumaDoble_tests, pares) {
    int pares[7] = {2,4,6,8,10,50,990};
    EXPECT_EQ(2140, sumaDoble(pares, 7));
}

TEST(sumaDoble_tests, mezcla) {
    int mezcla[12] = {-1, 0, 500, 22, -2, 35, 16, -10, 12, 66, 76, -2};
    EXPECT_EQ(1384, sumaDoble(mezcla, 12));
}

TEST(sumaDoble_tests, vacio) {
    int vacio[0] = {};
    EXPECT_EQ(0, sumaDoble(vacio, 0));
}

TEST(sumaDoble_tests, pares_neg) {
    int paresNeg[10] = {-2,1,1,1,-2,2,1,-2,-2,1};
    EXPECT_EQ(4, sumaDoble(paresNeg, 10));
}