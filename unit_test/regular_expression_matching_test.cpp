#include "gtest/gtest.h"

bool isMatch(const char *s, const char *p);
bool isMatch_ii(const char *s, const char *p);

TEST(RegularExpressionMatching, Normal)
{
    EXPECT_FALSE( isMatch("aa", "a") );
    EXPECT_TRUE( isMatch("aa", "aa") );
    EXPECT_FALSE( isMatch("aaa", "aa") );
    EXPECT_TRUE( isMatch("aa", "a*") );
    EXPECT_TRUE( isMatch("aa", ".*") );
    EXPECT_TRUE( isMatch("ab", ".*") );
    EXPECT_TRUE( isMatch("aab", "c*a*b") );

    EXPECT_TRUE( isMatch("a", "ab*") );
    EXPECT_FALSE( isMatch("a", "ab*a") );
    EXPECT_TRUE( isMatch("", "c*c*") );

    // test isMatch_ii()
    EXPECT_FALSE( isMatch_ii("aa", "a") );
    EXPECT_TRUE( isMatch_ii("aa", "aa") );
    EXPECT_FALSE( isMatch_ii("aaa", "aa") );
    EXPECT_TRUE( isMatch_ii("aa", "a*") );
    EXPECT_TRUE( isMatch_ii("aa", ".*") );
    EXPECT_TRUE( isMatch_ii("ab", ".*") );
    EXPECT_TRUE( isMatch_ii("aab", "c*a*b") );

    EXPECT_TRUE( isMatch_ii("a", "ab*") );
    EXPECT_FALSE( isMatch_ii("a", "ab*a") );
    EXPECT_TRUE( isMatch_ii("", "c*c*") );
}
