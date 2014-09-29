#include "gtest/gtest.h"

bool search_ii(int A[], int n, int target);

TEST(SearchInRotatedSortedArrayIITestCase, Normal)
{
    int A[7] = {4, 5, 6, 7, 0, 1, 2};

    EXPECT_FALSE(search_ii(A, 7, 3));
    EXPECT_TRUE(search_ii(A, 7, 5));
    EXPECT_TRUE(search_ii(A, 7, 1));

    int B[7] = {1, 2, 3, 1, 1, 1, 1};

    EXPECT_FALSE(search_ii(B, 7, 5));
    EXPECT_TRUE(search_ii(B, 7, 2));
}
