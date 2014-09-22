#include <iostream>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

void setZeroes(vector<vector<int> > &matrix);
void setZeroes_ii(vector<vector<int> > &matrix);


TEST(SetMatrixZeroesTestCase, Normal)
{
    vector<vector<int> > matrix;

    vector<int> line1;
    line1.push_back(0);
    line1.push_back(0);
    line1.push_back(0);
    line1.push_back(5);

    vector<int> line2;
    line2.push_back(4);
    line2.push_back(3);
    line2.push_back(1);
    line2.push_back(4);

    vector<int> line3;
    line3.push_back(0);
    line3.push_back(1);
    line3.push_back(1);
    line3.push_back(4);

    vector<int> line4;
    line4.push_back(1);
    line4.push_back(2);
    line4.push_back(1);
    line4.push_back(3);

    vector<int> line5;
    line5.push_back(0);
    line5.push_back(0);
    line5.push_back(1);
    line5.push_back(1);
   
    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);
    matrix.push_back(line4);
    matrix.push_back(line5);

    for(vector<vector<int> >::iterator it = matrix.begin(); it != matrix.end(); it++)
    {
        for(vector<int>::iterator it_ = (*it).begin(); it_ != (*it).end(); it_++)
        {
            cout << *it_ << " - ";
        }

        cout << endl;
    }

    //setZeroes(matrix);
    setZeroes_ii(matrix);

    cout << "after setZeroes:" << endl;
    for(vector<vector<int> >::iterator it = matrix.begin(); it != matrix.end(); it++)
    {
        for(vector<int>::iterator it_ = (*it).begin(); it_ != (*it).end(); it_++)
        {
            cout << *it_ << " - ";
        }

        cout << endl;
    }
}
