#include <iostream>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix);

TEST(SpiralMatrixTestCase, Normal)
{
    vector<vector<int> > matrix;
    vector<int> line1;
    line1.push_back(1);
    line1.push_back(2);
    line1.push_back(3);
    line1.push_back(4);

    vector<int> line2;
    line2.push_back(5);
    line2.push_back(6);
    line2.push_back(7);
    line2.push_back(8);

    vector<int> line3;
    line3.push_back(9);
    line3.push_back(10);
    line3.push_back(11);
    line3.push_back(12);

    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);

    vector<int> result = spiralOrder(matrix);

    for(vector<int>::iterator it=result.begin(); it != result.end(); it++)
    {
        cout << *it << " - ";
    }
    cout << endl;
}

TEST(SpiralMatrixTestCase, JustOneColumn)
{ 
    vector<vector<int> > matrix;
    vector<int> line1;
    line1.push_back(7);

    vector<int> line2;
    line2.push_back(9);

    vector<int> line3;
    line3.push_back(6);

    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);

    vector<int> result = spiralOrder(matrix);

    for(vector<int>::iterator it=result.begin(); it != result.end(); it++)
    {
        cout << *it << " - ";
    }
    cout << endl;
}

