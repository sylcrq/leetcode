#include "gtest/gtest.h"
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle);

TEST(TriangleTestCase, Normal)
{
    vector<vector<int> > triangle;

    int line1[1] = {2};
    int line2[2] = {3, 4};
    int line3[3] = {6, 5, 7};
    int line4[4] = {4, 1, 8, 3};

    vector<int> line1_(line1, line1+1);
    vector<int> line2_(line2, line2+2);
    vector<int> line3_(line3, line3+3);
    vector<int> line4_(line4, line4+4);

    triangle.push_back(line1_);
    triangle.push_back(line2_);
    triangle.push_back(line3_);
    triangle.push_back(line4_);

    EXPECT_EQ(11, minimumTotal(triangle));
}
