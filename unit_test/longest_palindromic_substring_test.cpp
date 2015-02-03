#include "gtest/gtest.h"
#include <string>

using namespace std;

string longestPalindrome(string s);
string longestPalindrome_ii(string s);

TEST(LongestPalindromicSubstringTestCase, Normal)
{
    EXPECT_STREQ("1", longestPalindrome("1").c_str());
    EXPECT_STREQ("aa", longestPalindrome("aa").c_str());
    EXPECT_STREQ("121", longestPalindrome("121").c_str());
    EXPECT_STREQ("aba", longestPalindrome("caba").c_str());
    EXPECT_STREQ("1221", longestPalindrome("a1221c").c_str());
    EXPECT_STREQ("aaabaaa", longestPalindrome("aaabaaaa").c_str());

    EXPECT_STREQ("1", longestPalindrome_ii("1").c_str());
    EXPECT_STREQ("aa", longestPalindrome_ii("aa").c_str());
    EXPECT_STREQ("121", longestPalindrome_ii("121").c_str());
    EXPECT_STREQ("aba", longestPalindrome_ii("caba").c_str());
    EXPECT_STREQ("1221", longestPalindrome_ii("a1221c").c_str());
    EXPECT_STREQ("aaabaaa", longestPalindrome_ii("aaabaaaa").c_str());
}
