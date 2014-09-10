#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows);

TEST(PascalsTriangleTestCase, Normal)
{
    vector<vector<int> > result = generate(5);

    for(size_t i=0; i<result.size(); i++)
    {
        for(size_t j=0; j<result[i].size(); j++)
        {
            cout << "[" << result[i][j] << "]";
        }
        cout << endl;
    }
}
