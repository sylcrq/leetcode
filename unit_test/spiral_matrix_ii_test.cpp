#include "gtest/gtest.h"

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n);

TEST(SpiralMatrixIITestCase, Normal)
{
    int n = 5;

    vector<vector<int> > result = generateMatrix(n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << result[i][j] << " - ";
        }
        cout << endl;
    }
}
