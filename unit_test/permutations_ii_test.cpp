#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > permuteUnique(vector<int> &num);


TEST(PermutationsIITestCase, Normal)
{
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);

    vector<vector<int> > result = permuteUnique(num);

    for(vector<vector<int> >::iterator it=result.begin(); it != result.end(); it++)
    {
        for(vector<int>::iterator it_=(*it).begin(); it_ != (*it).end(); it_++)
        {
            std::cout << *it_ << "-";
        }

        std::cout << std::endl;
    }
}
