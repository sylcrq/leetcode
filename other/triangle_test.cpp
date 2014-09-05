#include "gtest/gtest.h"

int form_a_valid_triangle(const int* array, int array_len);


TEST(TriangleTestCase, InvalidInput)
{
    int a[10] = {0};

    EXPECT_EQ(0, form_a_valid_triangle(NULL, 10));
    EXPECT_EQ(0, form_a_valid_triangle(a, 1));
    EXPECT_EQ(0, form_a_valid_triangle(NULL, 2));
}

TEST(TriangleTestCase, HaveResult)
{
    int a[5] = {3, 5, 7, 9, 11};

    EXPECT_EQ(7, form_a_valid_triangle(a, 5));
}

TEST(TriangleTestCase, NoResult)
{
    //int a[4] = {};

    //EXPECT_EQ(0, form_a_valid_triangle(a, 4));
}
