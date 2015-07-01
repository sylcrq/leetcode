#include "gtest/gtest.h"

bool isHappy(int n);

TEST(HappyNumberTestCase, Normal) {
    EXPECT_TRUE( isHappy(19) );
}
