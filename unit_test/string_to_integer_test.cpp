#include "gtest/gtest.h"
#include "limits.h"

int my_atoi(const char *str); 


TEST(StringToIntegerTestCase, Normal)
{
    EXPECT_EQ(0, my_atoi(NULL));
    EXPECT_EQ(0, my_atoi(""));
    EXPECT_EQ(0, my_atoi("  "));
    EXPECT_EQ(123, my_atoi("123"));
    EXPECT_EQ(-123, my_atoi("-123"));
    EXPECT_EQ(0, my_atoi("xyz"));
    EXPECT_EQ(34, my_atoi("34xyz"));
    EXPECT_EQ(-3, my_atoi("-3xyz"));
    EXPECT_EQ(0, my_atoi("-ab"));
    EXPECT_EQ(1, my_atoi("+1"));
    EXPECT_EQ(INT_MAX, my_atoi("9999999999999999999"));
    EXPECT_EQ(INT_MIN, my_atoi("-9999999999999999999"));
    EXPECT_EQ(INT_MAX, my_atoi("9223372036854775809"));
}
