#include "gtest/gtest.h"
#include <string>
#include <vector>

using namespace std;

bool exist(vector<vector<char> > &board, string word); 

TEST(WordSearchTestCase, Normal)
{
    char line_1[4] = {'A','B','C','E'};
    char line_2[4] = {'S','F','C','S'};
    char line_3[4] = {'A','D','E','E'};

    vector<vector<char> > board;
    board.push_back(vector<char>(line_1, line_1+4));
    board.push_back(vector<char>(line_2, line_2+4));
    board.push_back(vector<char>(line_3, line_3+4));

    EXPECT_TRUE(exist(board, "ABCCED"));
    EXPECT_TRUE(exist(board, "SEE"));
    EXPECT_FALSE(exist(board, "ABCB"));
}

