#include "gtest/gtest.h"
#include <string>

using namespace std;

int numDistinct(string S, string T);

TEST(DistinctSubsequencesTestCase, Normal)
{
    EXPECT_EQ(4, numDistinct("aabb", "ab"));
    EXPECT_EQ(3, numDistinct("ccc", "c"));
    EXPECT_EQ(1, numDistinct("b", "b"));
}

