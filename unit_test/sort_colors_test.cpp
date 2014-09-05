#include "gtest/gtest.h"

#include <iostream>

void sortColors(int A[], int n);
void sortColors_2(int A[], int n);


TEST(SortColorsTestCase, Normal)
{
    int array[10] = {0, 2, 1, 2, 1, 0, 2, 1, 1, 0};

    sortColors_2(array, 10);

    for(int i=0; i<10; i++)
        std::cout << array[i] << " - ";

    std::cout << std::endl;
}
