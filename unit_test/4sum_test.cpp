#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target);

TEST(FourSumTestCase, Normal)
{
    int number[6] = {1, 0, -1, 0, -2, 2};
    vector<int> num(number, number+6);

    vector<vector<int> > result = fourSum(num, 0);

    for(vector<vector<int> >::iterator it=result.begin(); it != result.end(); it++)
    {
        for(vector<int>::iterator it_=(*it).begin(); it_ != (*it).end(); it_++)
        {
            std::cout << *it_ << ", ";
        }

        std::cout << std::endl;
    }
}
