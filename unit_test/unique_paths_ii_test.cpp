#include "gtest/gtest.h"
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid);

TEST(UniquePathsIITestCase, Normal)
{
    vector<vector<int> > grid;

    int line1[] = {0, 0, 0};
    int line2[] = {0, 1, 0};
    int line3[] = {0, 0, 0};

    vector<int> line1_v(line1, line1 + sizeof(line1)/sizeof(int));
    vector<int> line2_v(line2, line2 + sizeof(line2)/sizeof(int));
    vector<int> line3_v(line3, line3 + sizeof(line3)/sizeof(int));

    grid.push_back(line1_v);
    grid.push_back(line2_v);
    grid.push_back(line3_v);

    EXPECT_EQ(2, uniquePathsWithObstacles(grid));
}

TEST(UniquePathsIITestCase, ObstacleAtStart)
{
    vector<vector<int> > grid;

    vector<int> line1;
    line1.push_back(1);

    grid.push_back(line1);

    EXPECT_EQ(0, uniquePathsWithObstacles(grid));
}
