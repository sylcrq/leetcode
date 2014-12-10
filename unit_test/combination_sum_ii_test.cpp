#include "gtest/gtest.h"
#include <vector>

using namespace std;

vector<vector<int> > combinationSum2(vector<int> &num, int target);

TEST(CombinationSumIITestCase, Normal)
{
    int number[7] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> num(number, number+7);

    vector<vector<int> > result = combinationSum2(num, 8);

    for(vector<vector<int> >::iterator it=result.begin(); it != result.end(); it++)
    {
        for(vector<int>::iterator it_=(*it).begin(); it_ != (*it).end(); it_++)
        {
            std::cout << *it_ << " - ";
        }

        std::cout << std::endl;
    }
}

TEST(CombinationSumIITestCase, AllNumIsSame)
{
    int number[3] = {2, 2, 2};
    vector<int> num(number, number+3);

    vector<vector<int> > result = combinationSum2(num, 4);

    for(vector<vector<int> >::iterator it=result.begin(); it != result.end(); it++)
    {
        for(vector<int>::iterator it_=(*it).begin(); it_ != (*it).end(); it_++)
        {
            std::cout << *it_ << " - ";
        }

        std::cout << std::endl;
    }
}
