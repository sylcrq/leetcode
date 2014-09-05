#include <iostream>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

vector<int> grayCode(int n);


TEST(GrayCodeTestCase, Normal)
{
    vector<int> result = grayCode(2);

    for(size_t i=0; i<result.size(); i++)
    {
        cout << result[i] << " - ";
    }
    cout << endl;

    //
    vector<int> result_2 = grayCode(4);

    for(size_t i=0; i<result_2.size(); i++)
    {
        cout << result_2[i] << " - ";
    }
    cout << endl;
}
