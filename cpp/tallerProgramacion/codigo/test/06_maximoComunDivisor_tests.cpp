#include "gtest/gtest.h"
#include "../src/taller.h"

TEST(maximoComunDivisor_tests, coprimos) {
    EXPECT_EQ(1, maximoComunDivisor(1,1));
    EXPECT_EQ(1, maximoComunDivisor(1, 2));
    EXPECT_EQ(1, maximoComunDivisor(17, 19));
    EXPECT_EQ(1, maximoComunDivisor(60, 17));
}

TEST(maximoComunDivisor_tests, mcd_en_extremos) {
    EXPECT_EQ(2, maximoComunDivisor(6, 2));
    EXPECT_EQ(10, maximoComunDivisor(100, 10));
    EXPECT_EQ(28, maximoComunDivisor(28, 56));
}

TEST(maximoComunDivisor_tests, mcd_con_cero) {
    EXPECT_EQ(100, maximoComunDivisor(100, 0));
    EXPECT_EQ(1, maximoComunDivisor(0, 1));
    EXPECT_EQ(28, maximoComunDivisor(28, 56));
}

TEST(maximoComunDivisor_tests, mcd_con_neg) {
    EXPECT_EQ(2, maximoComunDivisor(-6, 10));
    EXPECT_EQ(2, maximoComunDivisor(10, -6));
    EXPECT_EQ(28, maximoComunDivisor(28, 56));
}

TEST(maximoComunDivisor_tests, normal) {
    EXPECT_EQ(2, maximoComunDivisor(6, 10));
    EXPECT_EQ(18913, maximoComunDivisor(624129,2061517));
}