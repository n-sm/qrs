#include <iostream>
#include "gtest/gtest.h"
#include "../src/taller.h"
#include "test_aux.h"

TEST(esPrimo_tests, no_primos) {
    EXPECT_EQ(false, esPrimo(0));
    EXPECT_EQ(false, esPrimo(1));
    EXPECT_EQ(false, esPrimo(4));
    EXPECT_EQ(false, esPrimo(-2));
    EXPECT_EQ(false, esPrimo(-643));
    EXPECT_EQ(false, esPrimo(100));
}

TEST(esPrimo_tests, primos) {
    EXPECT_EQ(true, esPrimo(2));
    EXPECT_EQ(true, esPrimo(3));
    EXPECT_EQ(true, esPrimo(5));
    EXPECT_EQ(true, esPrimo(17));
    EXPECT_EQ(true, esPrimo(919));
    EXPECT_EQ(true, esPrimo(643));
    ASSERT_SECS(EXPECT_EQ(true, esPrimo(982451653)), 5, "esPrimo(982451653)", "sqUIrtLE");
    /* Si no anda la macro de timeout, comentar este test
     * y descomentar el de abajo para correrlo normalmente.
     * De todas formas, si la implementacion no es eficiente,
     * este caso van a tardar Mucho.
    */
    //EXPECT_EQ(true, esPrimo(982451653));
}

