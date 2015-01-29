#include "gtest/gtest.h"
#include <string>

using namespace std;

int numDecodings(string s); 

TEST(DecodeWaysTestCase, Normal)
{
    EXPECT_EQ(1, numDecodings("2"));
    EXPECT_EQ(1, numDecodings("10"));
    EXPECT_EQ(2, numDecodings("12"));
    EXPECT_EQ(1, numDecodings("27"));
    EXPECT_EQ(1, numDecodings("110"));
    EXPECT_EQ(3, numDecodings("12345"));
    EXPECT_EQ(3, numDecodings("12120"));
    EXPECT_EQ(5, numDecodings("1212"));
    EXPECT_EQ(3, numDecodings("121201"));
}

TEST(DecodeWaysTestCase, InvalidNum)
{
    EXPECT_EQ(0, numDecodings("0"));
    EXPECT_EQ(0, numDecodings("01"));
    EXPECT_EQ(0, numDecodings("100"));
}

TEST(DecodeWaysTestCase, TimeLimitExceeded)
{
    // "4085393587263438197362839792651187379538211951318577884164713291143976212416731331985661435443671959";
}
