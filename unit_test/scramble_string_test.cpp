#include "gtest/gtest.h"
#include <string>

using namespace std;

bool isScramble(string s1, string s2);

TEST(ScrambleStringTestCase, Normal)
{
    EXPECT_TRUE(isScramble("great", "rgeat"));
    EXPECT_TRUE(isScramble("great", "rgtae"));    
}
