#include "gtest/gtest.h"
#include <vector>

using namespace std;

int findMin(vector<int>& nums);

TEST(FindMinimumInRotatedSortedArrayTestCase, Normal) {
    int test_data[] = {4,5,6,7,0,1,2};
    vector<int> data(test_data, test_data + sizeof(test_data)/sizeof(int));

    EXPECT_EQ(0, findMin(data));
}

TEST(FindMinimumInRotatedSortedArrayTestCase, TwoNum) {
    int test_data[] = {1,2};
    vector<int> data(test_data, test_data + sizeof(test_data)/sizeof(int));

    EXPECT_EQ(1, findMin(data));
}

TEST(FindMinimumInRotatedSortedArrayTestCase, NoRotate) {
    int test_data[] = {1,2,3};
    vector<int> data(test_data, test_data + sizeof(test_data)/sizeof(int));

    EXPECT_EQ(1, findMin(data));
}
