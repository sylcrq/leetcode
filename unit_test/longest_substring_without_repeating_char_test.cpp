#include "gtest/gtest.h"

#include <string>

using namespace std;

int lengthOfLongestSubstring(string s);

TEST(LongestSubstringWithoutRepeatingCharTestCase, Normal)
{
    EXPECT_EQ(3, lengthOfLongestSubstring("abcabcbb"));
    EXPECT_EQ(1, lengthOfLongestSubstring("bbbbb"));

    EXPECT_EQ(12, lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco"));

    EXPECT_EQ(12, lengthOfLongestSubstring("qopubjguxhxdipfzwswybgfylqvjzhar"));
}

TEST(LongestSubstringWithoutRepeatingCharTestCase, EmptyString)
{
    string str;
    EXPECT_EQ(0, lengthOfLongestSubstring(str));
}
