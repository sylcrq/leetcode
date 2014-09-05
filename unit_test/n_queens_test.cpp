#include "gtest/gtest.h"

#include <string>
#include <vector>

using namespace std;

int totalNQueens(int n);
vector<vector<string> > solveNQueens(int n);

TEST(NQueensTestCase, Normal)
{
    // N-Queens II
    EXPECT_EQ(92, totalNQueens(8));

    // N-Queens
    vector<vector<string> > solutions = solveNQueens(8);

    for(size_t i=0; i<solutions.size(); i++)
    {
        cout << "solution: " << i+1 << endl;
        for(size_t j=0; j<solutions[i].size(); j++)
        {
            cout << solutions[i][j] << endl;
        }
    }
}
