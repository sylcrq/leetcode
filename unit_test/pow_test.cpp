#include "gtest/gtest.h"
#include <iostream>
#include <limits.h>

double pow(double x, int n);

TEST(PowTestCase, NEqualsIntMax)
{
    // std::numeric_limits<int>::max()
    // 2147483647
    double result = pow(0.00001, INT_MAX);
    std::cout << result << std::endl;
}

TEST(PowTestCase, NEqualsIntMin)
{
    // std::numeric_limits<int>::min()
    // -2147483648
    double result = pow(-1.00000, INT_MIN);
    std::cout << result << std::endl;
}

TEST(PowTestCase, NEqualsOne)
{
    double result = pow(8.95371, -1);
    std::cout << result << std::endl;
}

TEST(PowTestCase, NIsNegative)
{
    double result = pow(34.00515, -3);
    std::cout << result << std::endl;
}


