#include "gtest/gtest.h"

int trailingZeroes(int n);

TEST(FactorialTrailingZeroesTestCase, Normal) {
    EXPECT_EQ(1, trailingZeroes(5));
    EXPECT_EQ(2, trailingZeroes(10));
    EXPECT_EQ(6, trailingZeroes(25));
    EXPECT_EQ(452137076, trailingZeroes(1808548329));

    std::cout << "int " << sizeof(int) << std::endl;
    std::cout << "unsigned int " << sizeof(unsigned int) << std::endl;
    std::cout << "long " << sizeof(long) << std::endl;
    std::cout << "long long " << sizeof(long long) << std::endl;
}
