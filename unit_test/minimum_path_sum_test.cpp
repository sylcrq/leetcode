#include "gtest/gtest.h"
#include <vector>

using namespace std;

int minPathSum(vector<vector<int> > &grid);

TEST(MinimumPathSumTestCase, Normal)
{
    vector<vector<int> > grid;

    vector<int> line1;
    vector<int> line2;
    vector<int> line3;

    line1.push_back(1);
    line1.push_back(3);
    line1.push_back(1);

    line2.push_back(1);
    line2.push_back(5);
    line2.push_back(1);

    line3.push_back(4);
    line3.push_back(2);
    line3.push_back(1);

    grid.push_back(line1);
    grid.push_back(line2);
    grid.push_back(line3);

    EXPECT_EQ(7, minPathSum(grid));
}
