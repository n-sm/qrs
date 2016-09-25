#include <iostream>
#include "gtest/gtest.h"
#include "../src/taller.h"

TEST(esPrefijo_tests, vacio) {
    EXPECT_EQ(true, esPrefijo(" ", "  "));
    EXPECT_EQ(true, esPrefijo(" ", " espacio"));
    EXPECT_EQ(true, esPrefijo("", "prefijo"));
    EXPECT_EQ(true, esPrefijo("", ""));
    EXPECT_EQ(false, esPrefijo("   ", " prefijo"));
}

TEST(esPrefijo_tests, prefijos) {
    EXPECT_EQ(true, esPrefijo("pre", "prefijo"));
    EXPECT_EQ(true, esPrefijo("pref", "pref"));
    EXPECT_EQ(true, esPrefijo("_123", "_123nombreFeoFun"));
}

TEST(esPrefijo_tests, no_prefijos) {
    EXPECT_EQ(false, esPrefijo("prefijo", "pre"));
    EXPECT_EQ(false, esPrefijo("sufijo", "resufijo"));
    EXPECT_EQ(false, esPrefijo("prefi", "prefj"));
    EXPECT_EQ(false, esPrefijo("aaa", "AAAcodigo"));
    EXPECT_EQ(false, esPrefijo("esteEsMasLargo", "queEste"));
}