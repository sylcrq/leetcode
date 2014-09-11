#include "gtest/gtest.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generateParenthesis(int n);


TEST(GenerateParenthesesTestCase, Normal)
{
    vector<string> result = generateParenthesis(3);

    for(vector<string>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it << endl;
    }
}
