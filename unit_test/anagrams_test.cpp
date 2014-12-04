#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned int hash_code(string& str);
vector<string> anagrams(vector<string> &strs); 

TEST(AnagramsTestCase, HashFunction)
{
    string str1 = "";
    string str2 = "a";
    string str3 = "ab";

    EXPECT_EQ(0, hash_code(str1));
    EXPECT_EQ(97, hash_code(str2));
    EXPECT_EQ(12805, hash_code(str3));
}

TEST(AnagramsTestCase, Normal)
{
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("ate");
    strs.push_back("hello");
    strs.push_back("world");
    strs.push_back("tea");

    vector<string> result = anagrams(strs);

    for(vector<string>::iterator it=result.begin(); it != result.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}
