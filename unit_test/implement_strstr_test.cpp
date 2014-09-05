#include "gtest/gtest.h"

const char *strStr(const char *haystack, const char *needle);

TEST(StrstrTestCase, InvaidInput)
{
    const char* haystack = "hello world";
    const char* needle = "world";

    EXPECT_EQ(NULL, strStr(NULL, NULL));
    EXPECT_EQ(NULL, strStr(NULL, needle));
    EXPECT_EQ(haystack, strStr(haystack, NULL));
    EXPECT_EQ(NULL, strStr("haha", "hahaha"));
}

TEST(StrstrTestCase, Normal)
{
    const char* haystack = "hello world";
    const char* haystack2 = "hello world !";
    const char* needle = "world";

    EXPECT_EQ(haystack+6, strStr(haystack, needle));
    EXPECT_EQ(haystack2+6, strStr(haystack2, needle));
}
