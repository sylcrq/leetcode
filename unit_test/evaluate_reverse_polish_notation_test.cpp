#include "gtest/gtest.h"
#include <string>
#include <vector>

using namespace std;

int evalRPN(vector<string> &tokens);

TEST(EvaluateReversePolishNotationTestCase, Normal)
{
    vector<string> tokens_1;
    vector<string> tokens_2;
    tokens_1.push_back("2");
    tokens_1.push_back("1");
    tokens_1.push_back("+");
    tokens_1.push_back("3");
    tokens_1.push_back("*");

    tokens_2.push_back("4");
    tokens_2.push_back("13");
    tokens_2.push_back("5");
    tokens_2.push_back("/");
    tokens_2.push_back("+");

    EXPECT_EQ(9, evalRPN(tokens_1));
    EXPECT_EQ(6, evalRPN(tokens_2));
}

