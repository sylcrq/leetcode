#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(int A[], int n, int target);

TEST(SearchForARangeTestCase, Normal)
{
    int A[6] = {5, 7, 7, 8, 8, 10};

    vector<int> range = searchRange(A, 6, 8);
    std::cout << "[" << range[0] << ", " << range[1] << "]" << std::endl;

}
