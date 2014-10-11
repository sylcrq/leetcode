#include "gtest/gtest.h"
#include <string>

using namespace std;

bool isValid(string s);

TEST(ValidParenthesesTestCase, Normal)
{
    EXPECT_TRUE(isValid("()[]{}"));
    
    EXPECT_FALSE(isValid("([)]"));
}
