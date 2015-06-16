#include "gtest/gtest.h"

int hammingWeight(uint32_t n);

TEST(NumberOf1BitsTestCase, Normal) {
    EXPECT_EQ(3, hammingWeight(11));
    EXPECT_EQ(0, hammingWeight(0));
}
