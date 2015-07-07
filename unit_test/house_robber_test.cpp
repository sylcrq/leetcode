#include "gtest/gtest.h"
#include <vector>

using namespace std;

int rob(vector<int>& nums);

TEST(HouseRobberTestCase, Normal) {
    int test_nums[] = {1,2,3,4};
    vector<int> nums(test_nums, test_nums + sizeof(test_nums)/sizeof(int));

    EXPECT_EQ(6, rob(nums));
}
