#include <iostream>
#include "gtest/gtest.h"
#include "../src/taller.h"

TEST(pertenece_tests, no_pertenece_vacio) {
    int vacio[0] = {};
    EXPECT_EQ(false, pertenece(1, vacio, 0));
    EXPECT_EQ(false, pertenece(-1, vacio, 0));
    EXPECT_EQ(false, pertenece(0, vacio, 0));
}

TEST(pertenece_tests, pertenece_enteros) {
    int enteros[6] = {5, -323, 253, 0, -7, 100};
    int todosIguales[11] = {1,1,1,1,1,1,1,1,1,1,1};
    EXPECT_EQ(true, pertenece(0, enteros, 6));
    EXPECT_EQ(true, pertenece(-323, enteros, 6));
    EXPECT_EQ(true, pertenece(5, enteros, 6));
    EXPECT_EQ(true, pertenece(100, enteros, 6));
    EXPECT_EQ(true, pertenece(1, todosIguales, 11));
}

TEST(pertenece_tests, no_pertenece_enteros) {
    int enteros[6] = {5, -323, 253, 0, -7, 100};
    int todosIguales[11] = {1,1,1,1,1,1,1,1,1,1,1};
    EXPECT_EQ(false, pertenece(7, enteros, 6));
    EXPECT_EQ(false, pertenece(101, enteros, 6));
    EXPECT_EQ(false, pertenece(-1, todosIguales, 11));
}

