#include "gtest/gtest.h"

bool isPalindrome(int x);

TEST(PalindromeNumberTestCase, Normal)
{
    EXPECT_TRUE(isPalindrome(0));
    EXPECT_TRUE(isPalindrome(12321));

    EXPECT_FALSE(isPalindrome(-111));
    EXPECT_FALSE(isPalindrome(1234521));
}
