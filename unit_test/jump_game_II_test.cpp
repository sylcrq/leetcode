#include "gtest/gtest.h"

int jump(int A[], int n);

TEST(JumpGameIITestCase, Normal)
{
    int array[5] = {2, 3, 1, 1, 4};
    EXPECT_EQ( 2, jump(array, 5) );

    int array_2[7] = {1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ( 6, jump(array_2, 7) );

    int array_3[1] = {4};
    EXPECT_EQ( 0, jump(array_3, 1) );

    int array_4[5] = {3, 2, 1, 0, 4};
    EXPECT_EQ( -1, jump(array_4, 5) );
}
