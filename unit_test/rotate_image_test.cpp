#include <iostream>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

void rotate(vector< vector<int> >& matrix);


TEST(RotateImageTestCase, Normal)
{
    int n = 5;
    vector< vector<int> > matrix(n, vector<int>(n));

    // init data
    int num = 1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            matrix[i][j] = num++;
        }
    }

    // print
    cout << "before rotate:" << endl;
    for(size_t i=0; i<matrix.size(); i++)
    {
        for(size_t j=0; j<matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " - ";
        }
        cout << endl;
    }

    rotate(matrix);

    // print
    cout << "after rotate:" << endl;
    for(size_t i=0; i<matrix.size(); i++)
    {
        for(size_t j=0; j<matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " - ";
        }
        cout << endl;
    }
}
