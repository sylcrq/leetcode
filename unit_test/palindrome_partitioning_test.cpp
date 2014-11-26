#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string> > partition(string s);

TEST(PalindromePartitioningTestCase, Normal)
{
    vector<vector<string> > result = partition("aab");

    for(vector<vector<string> >::iterator it=result.begin(); it != result.end(); it++)
    {
        for(vector<string>::iterator it_=(*it).begin(); it_ != (*it).end(); it_++)
        {
            std::cout << *it_ << "-";
        }

        std::cout << std::endl;
    }
}
