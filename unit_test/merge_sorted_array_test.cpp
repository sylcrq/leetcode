#include "gtest/gtest.h"

#include <iostream>

void merge(int A[], int m, int B[], int n);

TEST(MergeSortedArrayTestCase, Normal)
{
    int A[15] = {1, 4, 6, 8, 12, 34, 35, 41};
    int B[6] = {11, 12, 15, 21, 22, 27};

    merge(A, 8, B, 6);

    for(int i=0; i<15; i++)
    {
        std::cout << A[i] << ", ";
    }

    std::cout << std::endl;
}
