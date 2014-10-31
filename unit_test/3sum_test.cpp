#include "gtest/gtest.h"
#include <iostream>
#include <vector>


using namespace std;

vector<vector<int> > threeSum(vector<int> &num);

TEST(ThreeSumTestCase, Normal)
{
    vector<int> num;
    num.push_back(-1);
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);
    num.push_back(-1);
    num.push_back(-4);

    vector<vector<int> > result = threeSum(num);

    for(vector<vector<int> >::iterator it=result.begin(); it != result.end(); it++)
    {
        std::cout << "[";

        for(vector<int>::iterator it_=(*it).begin(); it_ != (*it).end(); it_++)
        {
            std::cout << *it_ << ", ";
        }

        std::cout << "]" << std::endl;
    }
}
