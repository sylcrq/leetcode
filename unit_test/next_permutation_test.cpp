#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int> &num);

void print_vector(vector<int>& num)
{
    for(vector<int>::iterator it=num.begin(); it != num.end(); it++)
    {
        std::cout << *it << "-";
    }

    std::cout << std::endl;
}

TEST(NextPermutationTestCase, Normal)
{
    int num1[3] = {1, 2, 3};
    int num2[3] = {3, 2, 1};
    int num3[3] = {1, 1, 5};

    vector<int> num1_(num1, num1+3);
    vector<int> num2_(num2, num2+3);
    vector<int> num3_(num3, num3+3);

    nextPermutation(num1_);
    nextPermutation(num2_);
    nextPermutation(num3_);

    print_vector(num1_);
    print_vector(num2_);
    print_vector(num3_);
}
