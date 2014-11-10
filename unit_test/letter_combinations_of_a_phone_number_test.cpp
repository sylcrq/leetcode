#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits);

TEST(LetterCombinationsOfAPhoneNumberTestCase, Normal)
{
    vector<string> result = letterCombinations("23");

    for(vector<string>::iterator it=result.begin(); it != result.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}
