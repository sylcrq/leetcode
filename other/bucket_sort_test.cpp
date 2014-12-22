#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void my_print_vector(vector<int>& array);
void bucket_sort(vector<int>& array);

TEST(BucketSortTestCase, Normal)
{
    vector<int> array;

    srand(time(0));

    for(int i=0; i<200; i++)
    {
        array.push_back(rand() % 100);
    }

    vector<int> copy(array);

    std::cout << "before sort:" << std::endl;
    my_print_vector(array);

    bucket_sort(array);

    std::cout << "after sort:" << std::endl;
    my_print_vector(array);

    // validate
    std::sort(copy.begin(), copy.end());
    EXPECT_THAT(copy, ::testing::ContainerEq(array));
}
