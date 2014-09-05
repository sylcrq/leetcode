#include "gtest/gtest.h"

int maxSubArray(int A[], int n);
int maxSubArray_ii(int A[], int n);

TEST(MaximumSubarrayTestCase, Normal)
{
    int a[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int b[3] = {-2, -1, -3};

    EXPECT_EQ(6, maxSubArray(a, 9));
    EXPECT_EQ(-1, maxSubArray(b, 3));

    EXPECT_EQ(6, maxSubArray_ii(a, 9));
    EXPECT_EQ(-1, maxSubArray_ii(b, 3));
}
