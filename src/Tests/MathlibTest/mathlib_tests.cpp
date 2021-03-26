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
    EXPECT_EQ(Function::pow(5, 0), 1);
    EXPECT_EQ(Function::pow(9, 0.5), 3);
    EXPECT_EQ(Function::pow(16, 0.25), 2);
    EXPECT_EQ(Function::pow(0.25, 2), 0.0625);
    EXPECT_EQ(Function::pow(5, -1), 0.2);
    EXPECT_EQ(Function::pow(4, -0.5), 0.5);

    EXPECT_EQ(Function::pow(-4, 2), 16);
    EXPECT_EQ(Function::pow(-4, 3), -64);

    EXPECT_ANY_THROW(Function::pow(-4, 0.25));
    EXPECT_ANY_THROW(Function::pow(-4, 2.5));
}

