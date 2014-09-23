#include "gtest/gtest.h"

#include <iostream>

int removeDuplicates_ii(int A[], int n);
int removeDuplicates_ii_v2(int A[], int n);

TEST(RemoveDuplicatesFromSortedArrayIITestCase, Normal)
{
    int A[9] = {1, 1, 1, 1, 2, 3, 4, 4, 5};

    int array_size = sizeof(A) / sizeof(int);

    for(int i=0; i<array_size; i++)
    {
        std::cout << A[i] << " - ";
    }

    std::cout << std::endl;

    //int n = removeDuplicates_ii(A, array_size);
    int n = removeDuplicates_ii_v2(A, array_size);

    EXPECT_EQ(7, n);

    std::cout << "after:" << std::endl;

    for(int i=0; i<n; i++)
    {
        std::cout << A[i] << " - ";
    }

    std::cout << std::endl;
}
