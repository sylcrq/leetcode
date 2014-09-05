#include "gtest/gtest.h"
#include <string>

using namespace std;

string intToRoman(int num);


TEST(IntegerToRomanTestCase, Normal)
{
    EXPECT_STREQ("MMMCCCXXXIII", intToRoman(3333).c_str()); 
    EXPECT_STREQ("MDCCCLXXX", intToRoman(1880).c_str()); 
    EXPECT_STREQ("MCDXXXVII", intToRoman(1437).c_str()); 
    EXPECT_STREQ("DCCC", intToRoman(800).c_str()); 
    EXPECT_STREQ("CXCIX", intToRoman(199).c_str()); 
    EXPECT_STREQ("XVIII", intToRoman(18).c_str()); 
    EXPECT_STREQ("VII", intToRoman(7).c_str()); 
}
