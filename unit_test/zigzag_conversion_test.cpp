#include "gtest/gtest.h"
#include <string>
#include <stdio.h>

using namespace std;

string convert(string s, int nRows);
string convert_ii(string s, int nRows);

TEST(ZigZagConversionTestCase, Normal)
{
    string str = convert("PAYPALISHIRING", 3);
    string str_2 = convert_ii("PAYPALISHIRING", 3);

    printf("%s\n", str.c_str());
    printf("%s\n", str_2.c_str());
    //std::cout << str << std::endl;
    //std::cout << str_2 << std::endl;

    EXPECT_STREQ("PAHNAPLSIIGYIR", str.c_str());
    EXPECT_STREQ("PAHNAPLSIIGYIR", str_2.c_str());
}
