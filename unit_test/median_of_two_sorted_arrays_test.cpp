#include "gtest/gtest.h"

int findKthSortedArrays(int A[], int m, int B[], int n, int k);
double findMedianSortedArrays(int A[], int m, int B[], int n);

TEST(MedianOfTwoSortedArraysTestCase, FindKth)
{
    int A1[5] = {1,2,3,4,5};
    int B1[4] = {6,7,8,9};

    EXPECT_EQ(1, findKthSortedArrays(A1, 5, B1, 4, 0));
    EXPECT_EQ(3, findKthSortedArrays(A1, 5, B1, 4, 2));
    EXPECT_EQ(7, findKthSortedArrays(A1, 5, B1, 4, 6));
    EXPECT_EQ(9, findKthSortedArrays(A1, 5, B1, 4, 8));

    int A2[4] = {7,8,9,10};
    int B2[6] = {1,2,3,4,5,6};

    EXPECT_EQ(1, findKthSortedArrays(A2, 4, B2, 6, 0));
    EXPECT_EQ(4, findKthSortedArrays(A2, 4, B2, 6, 3));
    EXPECT_EQ(8, findKthSortedArrays(A2, 4, B2, 6, 7));
    EXPECT_EQ(10, findKthSortedArrays(A2, 4, B2, 6, 9));

    int A3[5] = {1,3,5,7,9};
    int B3[5] = {2,4,6,8,10};

    EXPECT_EQ(1, findKthSortedArrays(A3, 5, B3, 5, 0));
    EXPECT_EQ(2, findKthSortedArrays(A3, 5, B3, 5, 1));
    EXPECT_EQ(9, findKthSortedArrays(A3, 5, B3, 5, 8));
    EXPECT_EQ(10, findKthSortedArrays(A3, 5, B3, 5, 9));
}

TEST(MedianOfTwoSortedArraysTestCase, Normal)
{
    int A[5] = {1,3,5,7,9};
    int B[5] = {2,4,6,8,10};
    
    EXPECT_EQ(5.5, findMedianSortedArrays(A, 5, B, 5));
}

