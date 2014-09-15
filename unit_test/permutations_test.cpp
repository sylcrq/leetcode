#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > permute(vector<int> &num);

TEST(PermutationsTestCase, Normal)
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);

    vector<vector<int> > result = permute(num);

    // print result
    for(vector<vector<int> >::iterator it = result.begin(); it != result.end(); it++)
    {
        for(vector<int>::iterator it_ = (*it).begin(); it_ != (*it).end(); it_++)
        {
            cout << *it_ << " - ";
        }

        cout << endl;
    }
}
