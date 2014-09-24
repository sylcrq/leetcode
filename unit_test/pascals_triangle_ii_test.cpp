#include "gtest/gtest.h"

#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex);

TEST(PascalsTriangleIITestCase, Normal)
{
    vector<int> result = getRow(5);

    for(vector<int>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " - ";
    }

    cout << endl;
}
