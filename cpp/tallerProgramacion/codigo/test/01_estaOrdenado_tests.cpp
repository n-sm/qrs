#include "gtest/gtest.h"
#include "../src/taller.h"

TEST(estaOrdenado_tests, orden_descendente) {
    int ordDesc[5] = {123, 3, 0, -1, -123};
    EXPECT_EQ(true, estaOrdenado(ordDesc, 5));
}

TEST(estaOrdenado_tests, orden_ascendente) {
    int ordAsc[6] = {-501, 0, 12, 456, 501, 99999};
    EXPECT_EQ(true, estaOrdenado(ordAsc, 6));
}

TEST(estaOrdenado_tests, vacio) {
    int vacio[0] = {};
    EXPECT_EQ(true, estaOrdenado(vacio, 0));
}

TEST(estaOrdenado_tests, zig_zag) {
    int desord[7] = {-1, 0, 1, -1, 98, -56, 10};
    EXPECT_EQ(false, estaOrdenado(desord, 7));
}

TEST(estaOrdenado_tests, un_elemento) {
    int unoSolo[1] = {23};
    EXPECT_EQ(true, estaOrdenado(unoSolo, 1));
}

TEST(estaOrdenado_tests, dos_elementos) {
    int soloDos[2] = {1,2};
    EXPECT_EQ(true, estaOrdenado(soloDos, 2));
}

TEST(estaOrdenado_tests, escalera) {
    int desord[9] = {10, 20, 20, 350, 350, 10000, 10000, 99153, 100154};
    EXPECT_EQ(true, estaOrdenado(desord, 9));
}

TEST(estaOrdenado_tests, un_pico) {
    int pico[9] = {-4,-3,-2,-1,0,-1,-2,-3,-4};
    EXPECT_EQ(false, estaOrdenado(pico, 9));
}

TEST(estaOrdenado_tests, dos_picos) {
    int dosPicos[16] = {0,1,2,3,4,3,2,1,0,1,2,3,4,3,2,1};
    EXPECT_EQ(false, estaOrdenado(dosPicos, 16));
}

TEST(estaOrdenado_tests, iguales) {
    int iguales[10] = {0,0,0,0,0,0,0,0,0,0};
    EXPECT_EQ(true, estaOrdenado(iguales, 10));
}

