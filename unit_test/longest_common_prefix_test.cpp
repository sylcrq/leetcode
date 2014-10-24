#include "gtest/gtest.h"
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs);

TEST(LongestCommonPrefixTestCase, StringArrayEmpty)
{
    vector<string> strs;

    string prefix = longestCommonPrefix(strs);
    EXPECT_STREQ("", prefix.c_str());
}

TEST(LongestCommonPrefixTestCase, Normal)
{
    vector<string> strs;
    strs.push_back("hello world");
    strs.push_back("help!");
    strs.push_back("hell hell");
    strs.push_back("head");

    string prefix = longestCommonPrefix(strs);
    EXPECT_STREQ("he", prefix.c_str());
}
