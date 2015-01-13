#include "gtest/gtest.h"
#include <string>
#include <unordered_set>

using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict);

TEST(WordLadderTestCase, Normal)
{
    string start = "hit";
    string end = "cog";

    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    // "hit" -> "hot" -> "dot" -> "dog" -> "cog"
    EXPECT_EQ(5, ladderLength(start, end, dict));
}
