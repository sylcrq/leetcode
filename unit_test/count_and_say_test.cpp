#include "gtest/gtest.h"
#include <string>

using namespace std;

string countAndSay(int n);

TEST(CountAndSayTestCase, Normal)
{
    EXPECT_STREQ("1", countAndSay(1).c_str());
    EXPECT_STREQ("11", countAndSay(2).c_str());
    EXPECT_STREQ("21", countAndSay(3).c_str());
    EXPECT_STREQ("1211", countAndSay(4).c_str());
    EXPECT_STREQ("111221", countAndSay(5).c_str());
}

