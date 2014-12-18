#include "gtest/gtest.h"

void print_c_array(int array[], int n);
int firstMissingPositive(int A[], int n); 

TEST(FirstMissingPositiveTestCase, Normal)
{
    int array[3] = {1, 2, 0};
    int array2[4] = {3, 4, -1, 1};
    int array3[5] = {1, 2, 3, 4, 5};
    int array4[10] = {-1, 0, 13, 7, 5, -5, 10, 1, 2, 8};

    std::cout << "init:" << std::endl;
    print_c_array(array, 3);
    print_c_array(array2, 4);
    print_c_array(array3, 5);
    print_c_array(array4, 10);

    EXPECT_EQ(3, firstMissingPositive(array, 3));
    EXPECT_EQ(2, firstMissingPositive(array2, 4));
    EXPECT_EQ(6, firstMissingPositive(array3, 5));
    EXPECT_EQ(3, firstMissingPositive(array4, 10));

    std::cout << "output:" << std::endl;
    print_c_array(array, 3);
    print_c_array(array2, 4);
    print_c_array(array3, 5);
    print_c_array(array4, 10);
}
