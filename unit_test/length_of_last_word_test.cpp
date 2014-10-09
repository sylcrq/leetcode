#include "gtest/gtest.h"

int lengthOfLastWord(const char *s);
int lengthOfLastWord_ii(const char *s);

TEST(LengthOfLastWordTestCase, Normal)
{
    EXPECT_EQ(5, lengthOfLastWord("hello world"));
    EXPECT_EQ(0, lengthOfLastWord(""));
    EXPECT_EQ(1, lengthOfLastWord("a  "));

    EXPECT_EQ(5, lengthOfLastWord_ii("hello world"));
    EXPECT_EQ(0, lengthOfLastWord_ii(""));
    EXPECT_EQ(1, lengthOfLastWord_ii("a  "));
}
