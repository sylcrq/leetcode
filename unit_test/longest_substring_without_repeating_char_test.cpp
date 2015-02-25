#include "gtest/gtest.h"

#include <string>

using namespace std;

int lengthOfLongestSubstring(string s);
int lengthOfLongestSubstring_ii(string s);

TEST(LongestSubstringWithoutRepeatingCharTestCase, Normal)
{
    EXPECT_EQ(3, lengthOfLongestSubstring("abcabcbb"));
    EXPECT_EQ(1, lengthOfLongestSubstring("bbbbb"));
    EXPECT_EQ(12, lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco"));
    EXPECT_EQ(12, lengthOfLongestSubstring("qopubjguxhxdipfzwswybgfylqvjzhar"));

    EXPECT_EQ(3, lengthOfLongestSubstring_ii("abcabcbb"));
    EXPECT_EQ(1, lengthOfLongestSubstring_ii("bbbbb"));
    EXPECT_EQ(12, lengthOfLongestSubstring_ii("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco"));
    EXPECT_EQ(12, lengthOfLongestSubstring_ii("qopubjguxhxdipfzwswybgfylqvjzhar"));
}

TEST(LongestSubstringWithoutRepeatingCharTestCase, EmptyString)
{
    string str;
    EXPECT_EQ(0, lengthOfLongestSubstring(str));

    EXPECT_EQ(0, lengthOfLongestSubstring_ii(str));
}
