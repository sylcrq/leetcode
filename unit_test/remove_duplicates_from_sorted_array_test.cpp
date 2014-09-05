#include "gtest/gtest.h"

int removeDuplicates(int A[], int n);
int removeDuplicates_2(int A[], int n);

TEST(RemoveDuplicatesTestCase, InvalidInput)
{

}

TEST(RemoveDuplicatesTestCase, NoDuplicates)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};

    //EXPECT_EQ(10, removeDuplicates(a, 10));
    EXPECT_EQ(10, removeDuplicates_2(a, 10));
}

TEST(RemoveDuplicatesTestCase, AllDuplicates)
{
    int a[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    //EXPECT_EQ(1, removeDuplicates(a, 2));
    //EXPECT_EQ(1, removeDuplicates(a, 3));
    //EXPECT_EQ(1, removeDuplicates(a, 10));
    EXPECT_EQ(1, removeDuplicates_2(a, 10));
}

TEST(RemoveDuplicatesTestCase, Normal)
{
    int a[12] = {1, 3, 3, 5, 7, 12, 12, 13, 31, 45, 45, 45};

    //EXPECT_EQ(8, removeDuplicates(a, 12));
    EXPECT_EQ(8, removeDuplicates_2(a, 12));

    int b[3] = {10, 10, 12};
    //EXPECT_EQ(2, removeDuplicates(b, 3));
    EXPECT_EQ(2, removeDuplicates_2(b, 3));

    int c[5] = {1, 1, 2, 2, 3};
    //EXPECT_EQ(3, removeDuplicates(c, 5));
    EXPECT_EQ(3, removeDuplicates_2(c, 5));
}
