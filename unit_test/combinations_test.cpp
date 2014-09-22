#include <iostream>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

vector<vector<int> > combine(int n, int k);

TEST(CombinationsTestCase, Normal)
{
    vector<vector<int> > result = combine(4, 2);

    for(vector<vector<int> >::iterator it = result.begin(); it != result.end(); it++)
    {
        for(vector<int>::iterator it_ = (*it).begin(); it_ != (*it).end(); it_++)
        {
            cout << *it_ << " - ";
        }
        cout << endl;
    }
}
