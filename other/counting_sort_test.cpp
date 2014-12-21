#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void my_print_vector(vector<int>& array);
vector<int> counting_sort(vector<int>& array);

TEST(CountingSortTestCase, Normal)
{
    vector<int> array;

    srand(time(0));

    for(int i=0; i<200; i++)
    {
        array.push_back(rand() % 100);
    }

    vector<int> sorted = counting_sort(array);

    std::cout << "before sort:" << std::endl;
    my_print_vector(array);

    std::cout << "after sort:" << std::endl;
    my_print_vector(sorted);

    // validate
    std::sort(array.begin(), array.end());
    EXPECT_THAT(sorted, ::testing::ContainerEq(array));

    //for(size_t i=0; i<200; i++)
    //{
    //    EXPECT_EQ(array[i], sorted[i]);
    //}
}
