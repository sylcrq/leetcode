#include "gtest/gtest.h"
#include <stdlib.h>
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

    my_print_vector(array);
    my_print_vector(sorted);

    // validate
}

