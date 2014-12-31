#include "gtest/gtest.h"
#include <string>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict); 

TEST(WordBreakTestCase, Normal)
{
    unordered_set<string> dict;
    dict.insert("leet");
    dict.insert("code");

    EXPECT_TRUE(wordBreak("leetcode", dict));
}
