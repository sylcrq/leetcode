#include "gtest/gtest.h"

bool canJump(int A[], int n);


TEST(JumpGameTestCase, Normal)
{
    int jump[5] = {2, 3, 1, 1, 4};
    EXPECT_TRUE( canJump(jump, 5) );

    int jump_2[5] = {3, 2, 1, 0, 4};
    EXPECT_FALSE( canJump(jump_2, 5) );
}
