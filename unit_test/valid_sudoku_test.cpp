#include "gtest/gtest.h"
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board);

TEST(ValidSudokuTestCase, Normal)
{
    char line1[9] = {'5','3','.','.','7','.','.','.','.'};
    char line2[9] = {'6','.','.','1','9','5','.','.','.'};
    char line3[9] = {'.','9','8','.','.','.','.','6','.'};
    char line4[9] = {'8','.','.','.','6','.','.','.','3'};
    char line5[9] = {'4','.','.','8','.','3','.','.','1'};
    char line6[9] = {'7','.','.','.','2','.','.','.','6'};
    char line7[9] = {'.','6','.','.','.','.','2','8','.'};
    char line8[9] = {'.','.','.','4','1','9','.','.','5'};
    char line9[9] = {'.','.','.','.','8','.','.','7','9'};

    vector<char> line1_v(line1, line1+9);
    vector<char> line2_v(line2, line2+9);
    vector<char> line3_v(line3, line3+9);
    vector<char> line4_v(line4, line4+9);
    vector<char> line5_v(line5, line5+9);
    vector<char> line6_v(line6, line6+9);
    vector<char> line7_v(line7, line7+9);
    vector<char> line8_v(line8, line8+9);
    vector<char> line9_v(line9, line9+9);

    vector<vector<char> > board;
    board.push_back(line1_v);
    board.push_back(line2_v);
    board.push_back(line3_v);
    board.push_back(line4_v);
    board.push_back(line5_v);
    board.push_back(line6_v);
    board.push_back(line7_v);
    board.push_back(line8_v);
    board.push_back(line9_v);

    EXPECT_TRUE( isValidSudoku(board) );
}

