#include "gtest/gtest.h"

#include <iostream>

int partition(int* array, int len);
void quick_sort_recursive(int* array, int len);
void quick_sort(int* array, int len);

void PrintArray(int* array, int len)
{
    for(int i=0; i<len; i++)
        std::cout << array[i] << ", ";

    std::cout << std::endl;
}

TEST(QuickSortTestCase, PartitionFunc)
{
    int a[1] = {1};
    int b[2] = {1, 2};
    int c[5] = {1, 2, 3, 4, 5};
    int d[5] = {5, 4, 3, 2, 1};
    int e[5] = {3, 1, 4, 5, 2};

    EXPECT_EQ(0, partition(a, 1));
    EXPECT_EQ(0, partition(b, 2));
    EXPECT_EQ(0, partition(c, 5));
    EXPECT_EQ(4, partition(d, 5));
    EXPECT_EQ(2, partition(e, 5));

    PrintArray(a, 1);
    PrintArray(b, 2);
    PrintArray(c, 5);
    PrintArray(d, 5);
    PrintArray(e, 5);
}

TEST(QuickSortTestCase, Recursive)
{
    int a[1] = {1};
    int b[2] = {1, 2};
    int c[7] = {1, 2, 3, 4, 5, 6, 7};
    int d[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    int e[9] = {3, 1, 4, 5, 2, 3, 8, 12, 1};

    quick_sort_recursive(a, 1);
    quick_sort_recursive(b, 2);
    quick_sort_recursive(c, 7);
    quick_sort_recursive(d, 8);
    quick_sort_recursive(e, 9);

    PrintArray(a, 1);
    PrintArray(b, 2);
    PrintArray(c, 7);
    PrintArray(d, 8);
    PrintArray(e, 9);
}

TEST(QuickSortTestCase, NonRecursive)
{
    int a[1] = {1};
    int b[2] = {1, 2};
    int c[7] = {1, 2, 3, 4, 5, 6, 7};
    int d[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    int e[9] = {3, 1, 4, 5, 2, 3, 8, 12, 1};

    quick_sort(a, 1);
    quick_sort(b, 2);
    quick_sort(c, 7);
    quick_sort(d, 8);
    quick_sort(e, 9);

    PrintArray(a, 1);
    PrintArray(b, 2);
    PrintArray(c, 7);
    PrintArray(d, 8);
    PrintArray(e, 9);
}
