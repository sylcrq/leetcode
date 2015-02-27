#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

void solveSudoku(vector<vector<char> > &board);
void print_two_dimensional_vector(vector<vector<char> >& board);

TEST(SudokuSolverTestCase, Normal)
{
    char row_1[9] = {'5','3','.','.','7','.','.','.', '.'};
    char row_2[9] = {'6','.','.','1','9','5','.','.', '.'};
    char row_3[9] = {'.','9','8','.','.','.','.','6', '.'};
    char row_4[9] = {'8','.','.','.','6','.','.','.', '3'};
    char row_5[9] = {'4','.','.','8','.','3','.','.', '1'};
    char row_6[9] = {'7','.','.','.','2','.','.','.', '6'};
    char row_7[9] = {'.','6','.','.','.','.','2','8', '.'};
    char row_8[9] = {'.','.','.','4','1','9','.','.', '5'};
    char row_9[9] = {'.','.','.','.','8','.','.','7', '9'};

    vector<char> row_1_(row_1, row_1+9);
    vector<char> row_2_(row_2, row_2+9);
    vector<char> row_3_(row_3, row_3+9);
    vector<char> row_4_(row_4, row_4+9);
    vector<char> row_5_(row_5, row_5+9);
    vector<char> row_6_(row_6, row_6+9);
    vector<char> row_7_(row_7, row_7+9);
    vector<char> row_8_(row_8, row_8+9);
    vector<char> row_9_(row_9, row_9+9);

    vector<vector<char> > board;
    board.push_back(row_1_);
    board.push_back(row_2_);
    board.push_back(row_3_);
    board.push_back(row_4_);
    board.push_back(row_5_);
    board.push_back(row_6_);
    board.push_back(row_7_);
    board.push_back(row_8_);
    board.push_back(row_9_);

    print_two_dimensional_vector(board);

    solveSudoku(board);

    std::cout << "sudoku solved:" << std::endl;
    print_two_dimensional_vector(board);
}

