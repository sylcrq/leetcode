#include "gtest/gtest.h"
#include <string>

using namespace std;

string simplifyPath(string path);

TEST(SimplifyPathTestCase, Normal)
{
    string path_1 = simplifyPath("/home/");
    string path_2 = simplifyPath("/home/syl");
    string path_3 = simplifyPath("/a/./b/../../c/");
    string path_4 = simplifyPath("/../");
    string path_5 = simplifyPath("/home//foo/");

    EXPECT_STREQ("/home", path_1.c_str());
    EXPECT_STREQ("/home/syl", path_2.c_str());
    EXPECT_STREQ("/c", path_3.c_str());
    EXPECT_STREQ("/", path_4.c_str());
    EXPECT_STREQ("/home/foo", path_5.c_str());
}
