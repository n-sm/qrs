#include<iostream>
#include "gtest/gtest.h"
#include "../src/taller.h"

TEST(esCapicua_tests, capicua_long_variable) {
    EXPECT_EQ(true, esCapicua("x"));
    EXPECT_EQ(true, esCapicua("anna"));
    EXPECT_EQ(true, esCapicua("madam"));
    EXPECT_EQ(true, esCapicua("aaabcdedcbaaa"));
    EXPECT_EQ(true, esCapicua("122353221"));
    EXPECT_EQ(true, esCapicua("wasitacatisaw"));
}

TEST(esCapicua_tests, vacios) {
    EXPECT_EQ(true, esCapicua(""));
    EXPECT_EQ(true, esCapicua("  "));
    EXPECT_EQ(true, esCapicua(" "));
}

TEST(esCapicua_tests, no_capicua) {
    EXPECT_EQ(false, esCapicua("askdjadh812"));
    EXPECT_EQ(false, esCapicua("NADoNAD"));
    EXPECT_EQ(false, esCapicua("blabla"));
    EXPECT_EQ(false, esCapicua("blalba"));
}

TEST(esCapicua_tests, con_espacios) {
    EXPECT_EQ(false, esCapicua("anna "));
    EXPECT_EQ(false, esCapicua("anita lava la tina"));
    EXPECT_EQ(false, esCapicua(" anna"));
}

TEST(esCapicua_tests, caracteres_especiales) {
    /* Dependiendo de como lo resuelvan,
     * es muy posible que aca les falle un caso
     * siempre. Cuando debuggeen se
     * llevaran una sorpresa! */
    EXPECT_EQ(false, esCapicua("áa"));
    EXPECT_EQ(false, esCapicua("bB"));
    EXPECT_EQ(true, esCapicua("1á1"));
}


