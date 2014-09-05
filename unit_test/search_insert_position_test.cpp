#include "gtest/gtest.h"

int searchInsert(int A[], int n, int target);
int searchInsert_ii(int A[], int n, int target);

TEST(SearchInsertPositionTestCase, Normal)
{
    int A[4] = {1, 3, 5, 6};
    EXPECT_EQ(2, searchInsert(A, 4, 5));
    EXPECT_EQ(1, searchInsert(A, 4, 2));
    EXPECT_EQ(4, searchInsert(A, 4, 7));
    EXPECT_EQ(0, searchInsert(A, 4, 0));

    EXPECT_EQ(2, searchInsert_ii(A, 4, 5));
    EXPECT_EQ(1, searchInsert_ii(A, 4, 2));
    EXPECT_EQ(4, searchInsert_ii(A, 4, 7));
    EXPECT_EQ(0, searchInsert_ii(A, 4, 0));
}
