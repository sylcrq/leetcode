#include "gtest/gtest.h"

int search(int A[], int n, int target);

TEST(SearchInRotatedSortedArrayTestCase, Normal)
{
    int A[7] = {4, 5, 6, 7, 0, 1, 2};

    EXPECT_EQ(-1, search(A, 7, 3));
    EXPECT_EQ(1, search(A, 7, 5));
    EXPECT_EQ(5, search(A, 7, 1));

    int B[7] = {5, 6, 7, 0, 1, 2, 4};

    EXPECT_EQ(-1, search(B, 7, 3));
    EXPECT_EQ(0, search(B, 7, 5));
    EXPECT_EQ(5, search(B, 7, 2));
}
