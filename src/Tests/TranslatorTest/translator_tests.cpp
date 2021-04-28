//============================================================================//
/*
* IVS, Project 2 solution
* Authors: xhavlo01 xdovbu00 xhaltm02 xkolar80
* GNU General Public License v3
*/
//============================================================================//
/**
* @file translator_tests.cpp
* @brief utit tests for the Translator class
* @author Andrii Dovbush, xdovbu00
* @author Anton Havlovskyi, xhavlo01
* @author Ondřej Kolařík, xkolar80
* @author Adam Haltmar, xhaltm02
*/
//============================================================================//

#include "gtest/gtest.h"
#include "controller.h"

class TranslatorTest : public ::testing::Test
{
protected:
    virtual void SetUp() {
    }
};

/*
* @Author - Andrii Dovbush, xdovbu00
*/
TEST_F(TranslatorTest, StrToDouble) {
    EXPECT_EQ(Translator::StrWithBaseToNum("101", 2), 5);
    EXPECT_EQ(Translator::StrWithBaseToNum("101", 3), 10);
    EXPECT_EQ(Translator::StrWithBaseToNum("101", 4), 17);

    EXPECT_EQ(Translator::StrWithBaseToNum("-101", 2), -5);

    EXPECT_ANY_THROW(Translator::StrWithBaseToNum("121", 2));
    EXPECT_ANY_THROW(Translator::StrWithBaseToNum("1B1", 8));

    EXPECT_EQ(Translator::StrWithBaseToNum("1A", 11), 21);
    EXPECT_EQ(Translator::StrWithBaseToNum("3F", 16), 63);

    EXPECT_EQ(Translator::StrWithBaseToNum("-1A", 11), -21);
    EXPECT_EQ(Translator::StrWithBaseToNum("--1A", 11), 21);
    EXPECT_EQ(Translator::StrWithBaseToNum("---1A", 11), -21);

    EXPECT_ANY_THROW(Translator::StrWithBaseToNum("0", 1));
    EXPECT_ANY_THROW(Translator::StrWithBaseToNum("1B1", 17));

    //TODO: FRACTION TESTS
    EXPECT_EQ(Translator::StrWithBaseToNum("10.01", 2), 2.25);
}

/*
* @Author - Anton Havlovskyi, xhavlo01
*/
