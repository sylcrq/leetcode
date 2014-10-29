#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &S);

TEST(SubsetsIITestCase, Normal)
{
    vector<int> S;
    S.push_back(1);
    S.push_back(2);
    S.push_back(2);

    vector<vector<int> > result = subsetsWithDup(S);

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
