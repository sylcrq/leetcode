#include "gtest/gtest.h"
#include <vector>

using namespace std;

int findMin_ii(vector<int>& nums);

TEST(FindMinimumInRotatedSortedArrayIITestCase, Normal) {
    int test_data[] = {4,5,6,7,0,1,2};
    vector<int> data(test_data, test_data + sizeof(test_data)/sizeof(int));

    EXPECT_EQ(0, findMin_ii(data));
}

TEST(FindMinimumInRotatedSortedArrayIITestCase, NoRotate) {
    int test_data[] = {1,2,3};
    vector<int> data(test_data, test_data + sizeof(test_data)/sizeof(int));

    EXPECT_EQ(1, findMin_ii(data));
}

TEST(FindMinimumInRotatedSortedArrayIITestCase, ContainDuplicates) {
    int test_data[] = {10,1,10,10,10};
    vector<int> data(test_data, test_data + sizeof(test_data)/sizeof(int));

    EXPECT_EQ(1, findMin_ii(data));
}
