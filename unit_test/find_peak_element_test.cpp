#include "gtest/gtest.h"
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums);
int findPeakElement_ii(vector<int>& nums);
int findPeakElement_iii(vector<int>& nums);

TEST(FindPeakElementTestCase, Normal) {
    int test_data[] = {1,2,3,1};
    vector<int> data(test_data, test_data + sizeof(test_data)/sizeof(int));

    EXPECT_EQ(2, findPeakElement(data));
    EXPECT_EQ(2, findPeakElement_ii(data));
    EXPECT_EQ(2, findPeakElement_iii(data));
}
