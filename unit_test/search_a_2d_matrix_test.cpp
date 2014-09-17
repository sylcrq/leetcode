#include "gtest/gtest.h"
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target);


TEST(Searcha2DMatrixTestCase, Normal)
{
    vector<vector<int> > matrix;

    vector<int> line1;
    line1.push_back(1);

    matrix.push_back(line1);

    EXPECT_TRUE(searchMatrix(matrix, 1));
}
