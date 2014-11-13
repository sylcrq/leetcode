#include "gtest/gtest.h"
#include <string>

using namespace std;

int minDistance(string word1, string word2);

TEST(EditDistanceTestCase, Normal)
{
    EXPECT_EQ(3, minDistance("abc", "def"));
    EXPECT_EQ(1, minDistance("a", "b"));
}
