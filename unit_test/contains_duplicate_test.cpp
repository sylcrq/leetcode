#include "gtest/gtest.h"
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums);

TEST(ContainsDuplicateTestCase, Normal) {
    vector<int> nums;
    EXPECT_FALSE(containsDuplicate(nums));

    nums.push_back(4);
    nums.push_back(9);
    nums.push_back(7);
    nums.push_back(4);
    EXPECT_TRUE(containsDuplicate(nums));
}
