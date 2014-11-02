#include "gtest/gtest.h"
#include <vector>

using namespace std;

int threeSumClosest(vector<int> &num, int target);


TEST(ThreeSumClosestTestCase, Normal)
{
    vector<int> num;
    num.push_back(-1);
    num.push_back(2);
    num.push_back(1);
    num.push_back(-4);

    EXPECT_EQ(2, threeSumClosest(num, 1));
}
