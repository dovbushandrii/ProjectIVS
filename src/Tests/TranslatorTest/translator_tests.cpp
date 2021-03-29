//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test-Driven-Development 
//
// $NoKeywords: $ivs_project_2 $translator_tests.cpp
// $Author:     
// $Date:       $2021-03-26
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
