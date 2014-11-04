#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > combinationSum(vector<int> &candidates, int target);


TEST(CombinationSumTestCase, Normal)
{
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);

    vector<vector<int> > result = combinationSum(candidates, 7);

    for(vector<vector<int> >::iterator it=result.begin(); it != result.end(); it++)
    {
        std::cout << "[";

        for(vector<int>::iterator it_=(*it).begin(); it_ != (*it).end(); it_++)
        {
            std::cout << *it_ << ",";
        }

        std::cout << "]" << std::endl;
    }
}
