#include <iostream>
#include "gtest/gtest.h"
#include "../src/taller.h"
#include "test_aux.h"

TEST(fibonacci_tests, primeros_terminos) {
    EXPECT_EQ(0, fibonacci(0));
    EXPECT_EQ(1, fibonacci(1));
    EXPECT_EQ(1, fibonacci(2));
    EXPECT_EQ(2, fibonacci(3));
    EXPECT_EQ(3, fibonacci(4));
    EXPECT_EQ(5, fibonacci(5));
    EXPECT_EQ(13, fibonacci(7));
    EXPECT_EQ(610, fibonacci(15));
    EXPECT_EQ(987, fibonacci(16));
}

TEST(fibonacci_tests, terminos_grandes) {
    ASSERT_SECS(EXPECT_EQ(1134903170, fibonacci(45)), 5, "fibonacci(45)", "1t3r4t1v0");
    ASSERT_SECS(EXPECT_EQ(12586269025, fibonacci(50)), 8, "fibonacci(50)", "1t3r4t1v0)");
    /* Si no anda la macro de timeout, comentar esos tests
     * y descomentar los de abajo para correrlos normalmente.
     * De todas formas, si la implementacion no es eficiente,
     * estos casos van a tardar Mucho.
    */
    //EXPECT_EQ(1134903170, fibonacci(45));
    //EXPECT_EQ(12586269025, fibonacci(50));
}