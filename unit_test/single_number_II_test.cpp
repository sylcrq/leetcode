#include "gtest/gtest.h"


int singleNumber_ii(int A[], int n);

TEST(SingleNumberIITestCase, Normal)
{
    int a[11] = {3, 2, 3, 3, 2, 2, 45, 23, 45, 23, 45};

    EXPECT_EQ(23, singleNumber_ii(a, 11));
}
