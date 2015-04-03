#include "gtest/gtest.h"
#include <string>

using namespace std;

int longestValidParentheses(string s);

TEST(LongestValidParenthesesTestCase, Normal)
{
    EXPECT_EQ(2, longestValidParentheses("(()"));
    EXPECT_EQ(4, longestValidParentheses(")()()"));
    EXPECT_EQ(0, longestValidParentheses(""));
    EXPECT_EQ(4, longestValidParentheses("((())"));

    EXPECT_EQ(2, longestValidParentheses("()(()"));
}
