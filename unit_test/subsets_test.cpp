#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > subsets(vector<int> &S);

TEST(SubsetsTestCase, Normal)
{
    vector<int> S;
    S.push_back(2);
    S.push_back(3);
    S.push_back(1);
    S.push_back(4);

    vector<vector<int> > result = subsets(S);

    for(size_t i=0; i<result.size(); i++)
    {
        for(size_t j=0; j<result[i].size(); j++)
        {
            std::cout << result[i][j] << ", ";
        }

        std::cout << std::endl;
    }
}
