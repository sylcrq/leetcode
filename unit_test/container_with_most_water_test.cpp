#include "gtest/gtest.h"
#include <vector>

using namespace std;

int maxArea(vector<int> &height);

TEST(ContainerWithMostWaterTestCase, Normal)
{
    vector<int> height;
    height.push_back(5);
    height.push_back(8);
    height.push_back(3);
    height.push_back(1);

    EXPECT_EQ(6, maxArea(height));
}
