#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>
#include <vector>

using namespace std;

vector<int> findSubstring(string S, vector<string> &L);


TEST(SubstringWithConcatenationOfAllWordsTestCase, Normal)
{
    string str("barfoothefoobarman");
    string word1("foo");
    string word2("bar");

    vector<string> list;
    list.push_back(word1);
    list.push_back(word2);

    vector<int> result = findSubstring(str, list);
    // 0, 9
    EXPECT_THAT(result, ::testing::ElementsAre(0, 9));
}

TEST(SubstringWithConcatenationOfAllWordsTestCase, Duplicate)
{
    string str("lingmindraboofooowingdingbarrwingmonkeypoundcake");
    string word1("fooo");
    string word2("barr");
    string word3("wing");
    string word4("ding");
    string word5("wing");

    vector<string> list;
    list.push_back(word1);
    list.push_back(word2);
    list.push_back(word3);
    list.push_back(word4);
    list.push_back(word5);

    vector<int> result = findSubstring(str, list);
    // 13
    EXPECT_THAT(result, ::testing::ElementsAre(13));
}

TEST(SubstringWithConcatenationOfAllWordsTestCase, Simple)
{
    string str("aaa");
    string word1("a");
    string word2("a");

    vector<string> list;
    list.push_back(word1);
    list.push_back(word2);

    vector<int> result = findSubstring(str, list);
    // 0, 1
    EXPECT_THAT(result, ::testing::ElementsAre(0, 1));
}
