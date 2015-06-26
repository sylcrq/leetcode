#include "gtest/gtest.h"
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums);
int majorityElement_ii(vector<int>& nums);

TEST(MajorityElementTestCase, Normal) {
    int test_data[] = {1,2,3,4,2,2,2,2,1};
    vector<int> data(test_data, test_data + sizeof(test_data)/sizeof(int));

    EXPECT_EQ(2, majorityElement(data));
    EXPECT_EQ(2, majorityElement_ii(data));
}
