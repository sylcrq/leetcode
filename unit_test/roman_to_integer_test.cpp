#include "gtest/gtest.h"

#include <string>

using namespace std;

extern int romanToInt(string s);

TEST(RomanToIntegerTestCase, Normal)
{
    EXPECT_EQ(5, romanToInt("V"));
    EXPECT_EQ(8, romanToInt("VIII"));
    EXPECT_EQ(199, romanToInt("CXCIX"));
    EXPECT_EQ(800, romanToInt("DCCC"));
    EXPECT_EQ(1437, romanToInt("MCDXXXVII"));
    EXPECT_EQ(1900, romanToInt("MCM"));

}

