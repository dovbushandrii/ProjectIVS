

//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test-Driven-Development 
//
// $NoKeywords: $ivs_project_2 $mathlib_tests.cpp
// $Author:     
// $Date:       $2021-03-25
//============================================================================//

#include "gtest/gtest.h"
#include "mathlib.h"


class MathlibTwoArgs : public ::testing::Test
{
protected:
    virtual void SetUp() {
    }
};

class EquationTest : public ::testing::Test
{
protected:
    virtual void SetUp() {
    }
};

/*
* @Author - Andrii Dovbush, xdovbu00
*/
TEST_F(MathlibTwoArgs, Div) {
    EXPECT_ANY_THROW(Function::div(1, 0));
    EXPECT_ANY_THROW(Function::div(0, 0));
    EXPECT_EQ(Function::div(4, 2), 2);
    EXPECT_EQ(Function::div(4, -2), -2);
    EXPECT_EQ(Function::div(4, 0.25), 16);
    EXPECT_EQ(Function::div(4, -0.25), 16);
    EXPECT_EQ(Function::div(0.25, 0.25), 1);
    EXPECT_EQ(Function::div(0, 0.25), 0);
}

/*
* @Author - Andrii Dovbush, xdovbu00
*/
TEST_F(MathlibTwoArgs, Pow) {
    EXPECT_EQ(Function::power(5, 0), 1);
    EXPECT_EQ(Function::power(9, 0.5), 3);
    EXPECT_EQ(Function::power(16, 0.25), 2);
    EXPECT_EQ(Function::power(0.25, 2), 0.0625);
    EXPECT_EQ(Function::power(5, -1), 0.2);
    EXPECT_EQ(Function::power(4, -0.5), 0.5);

    EXPECT_EQ(Function::power(-4, 2), 16);
    EXPECT_EQ(Function::power(-4, 3), -64);

    EXPECT_ANY_THROW(Function::power(-4, 0.25));
    EXPECT_ANY_THROW(Function::power(-4, 2.5));
}

/*
* @Author - Anton Havlovskyi, xhavlo01
*/
TEST_F(MathlibTwoArgs, Mul) {
    EXPECT_EQ(Function::mul(2, 2), 4);
    EXPECT_EQ(Function::mul(2, 0.5), 1);
    EXPECT_EQ(Function::mul(2, 0.25), 0.5);
    EXPECT_EQ(Function::mul(2, 0.125), 0.25);
    EXPECT_EQ(Function::mul(0.25, 4), 1);
    EXPECT_EQ(Function::mul(0.5, 10), 5);
    EXPECT_EQ(Function::mul(0.625, 10), 6.25);
    EXPECT_EQ(Function::mul(0.5, 0.5), 0.25);
    EXPECT_EQ(Function::mul(0.2, 0.2), 0.04);

    EXPECT_EQ(Function::mul(2, -2), -4);
    EXPECT_EQ(Function::mul(-2, 2), -4);
    EXPECT_EQ(Function::mul(-2, -2), 4);
}

/*
* @Author - Anton Havlovskyi, xhavlo01
*/
TEST_F(MathlibTwoArgs, Root) {
    EXPECT_EQ(Function::root(4, 2), 2);
    EXPECT_EQ(Function::root(16, 2), 4);
    EXPECT_EQ(Function::root(36, 2), 6);
    EXPECT_EQ(Function::root(49, 2), 7);
    EXPECT_EQ(Function::root(8, 3), 2);
    EXPECT_EQ(Function::root(27, 3), 3);
    EXPECT_EQ(Function::root(64, 3), 4);
    EXPECT_EQ(Function::root(16777216, 8), 8);

    EXPECT_ANY_THROW(Function::root(-4, 2));
    EXPECT_EQ(Function::root(-8, 3), -2);
    EXPECT_ANY_THROW(Function::root(-16777216, 8));
}

/*
* @Author - Anton Havlovskyi, xhavlo01
*/
TEST_F(EquationTest, EquationClassTest) {
    EXPECT_EQ(Equation::solveEquation("2+2"), 4);
    EXPECT_EQ(Equation::solveEquation("2-2"), 0);
    EXPECT_EQ(Equation::solveEquation("2^2"), 4);
    EXPECT_EQ(Equation::solveEquation("2*2"), 4);
    EXPECT_EQ(Equation::solveEquation("2/2"), 1);
    EXPECT_EQ(Equation::solveEquation("2-2"), 0);

    EXPECT_EQ(Equation::solveEquation("(2+2)*(3+1) - 6^2 + 64^(1/3)*sqrt(25)"), 20);
    EXPECT_ANY_THROW(Equation::solveEquation("(2+2)*(3+1) - 6^2 + 64^(1/3)*sqrt(-25)"));
}
