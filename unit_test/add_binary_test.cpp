#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b);

TEST(AddBinaryTestCase, Normal)
{
    string s = addBinary("11", "1");
    cout << s << endl;

    EXPECT_STREQ("100", s.c_str());
}
