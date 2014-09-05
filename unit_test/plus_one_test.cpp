#include <iostream>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

vector<int> plusOne(vector<int> &digits);

TEST(PlusOneTestCase, Normal)
{
    vector<int> test;
    test.push_back(3);
    test.push_back(7);
    test.push_back(4);
    test.push_back(5);
    test.push_back(2);

    vector<int> result = plusOne(test);

    for(size_t i=0; i<result.size(); i++)
    {
        cout << result[i] << " - ";
    }

    cout << endl;

    vector<int> test_2;
    test_2.push_back(9);
    test_2.push_back(9);
    test_2.push_back(9);
    test_2.push_back(9);

    vector<int> result_2 = plusOne(test_2);

    for(size_t i=0; i<result_2.size(); i++)
    {
        cout << result_2[i] << " - ";
    }

    cout << endl;
}

