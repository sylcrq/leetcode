#include "gtest/gtest.h"

#include <iostream>

int removeElement(int A[], int n, int elem);
int removeElement_ii(int A[], int n, int elem);

TEST(RemoveElementTestCase, Normal)
{
    int a[10] = {1, 3, 4, 5, 2, 1, 1, 8, 1, 0};

    int size = sizeof(a) / sizeof(int);  // 数组大小

    for(int i=0; i<size; i++)
    {
        std::cout << a[i] << " - ";
    }

    std::cout << std::endl;

    int n = removeElement_ii(a, size, 1);

    for(int i=0; i<n; i++)
    {
        std::cout << a[i] << " - ";
    }

    std::cout << std::endl;
}
