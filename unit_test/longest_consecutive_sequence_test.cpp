#include "gtest/gtest.h"
#include <vector>

using namespace std;

int longestConsecutive(vector<int> &num);

TEST(LongestConsecutiveSequenceTestCase, Normal)
{
    vector<int> num;
    num.push_back(100);
    num.push_back(4);
    num.push_back(200);
    num.push_back(1);
    num.push_back(3);
    num.push_back(2);

    EXPECT_EQ(4, longestConsecutive(num));
}
