#include "gtest/gtest.h"


int singleNumber(int A[], int n);


TEST(SingleNumberTestCase, Normal)
{
    int a[1] = {3};
    int b[9] = {1, 3, 33, 23, 33, 3, 1, 7, 23};

    EXPECT_EQ(3, singleNumber(a, 1));
    EXPECT_EQ(7, singleNumber(b, 9));
}
