#include "gtest/gtest.h"
#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<char>> &board);
void print_two_dimensional_vector(vector<vector<char> >& board);

TEST(SurroundedRegionsTestCase, Normal)
{
    char line_1[4] = {'X','X','X','X'};
    char line_2[4] = {'X','O','O','X'};
    char line_3[4] = {'X','X','O','X'};
    char line_4[4] = {'X','O','X','X'};

    vector<vector<char> > board;
    board.push_back(vector<char>(line_1, line_1+4));
    board.push_back(vector<char>(line_2, line_2+4));
    board.push_back(vector<char>(line_3, line_3+4));
    board.push_back(vector<char>(line_4, line_4+4));

    print_two_dimensional_vector(board);

    solve(board);

    std::cout << "after:" << std::endl;
    print_two_dimensional_vector(board);
}

TEST(SurroundedRegionsTestCase, NoSurrounded)
{
    char line_1[6] = {'O','O','O','O','X','X'};
    char line_2[6] = {'O','O','O','O','O','O'};
    char line_3[6] = {'O','X','O','X','O','O'};
    char line_4[6] = {'O','X','O','O','X','O'};
    char line_5[6] = {'O','X','O','X','O','O'};
    char line_6[6] = {'O','X','O','O','O','O'};

    vector<vector<char> > board;
    board.push_back(vector<char>(line_1, line_1+6));
    board.push_back(vector<char>(line_2, line_2+6));
    board.push_back(vector<char>(line_3, line_3+6));
    board.push_back(vector<char>(line_4, line_4+6));
    board.push_back(vector<char>(line_5, line_5+6));
    board.push_back(vector<char>(line_6, line_6+6));

    print_two_dimensional_vector(board);

    solve(board);

    std::cout << "after:" << std::endl;
    print_two_dimensional_vector(board);
}

void print_two_dimensional_vector(vector<vector<char> >& board)
{
    // auto: C++11
    for(auto it=board.begin(); it != board.end(); it++)
    {
        for(auto it_=(*it).begin(); it_ != (*it).end(); it_++)
        {
            std::cout << *it_ << " ";
        }
        std::cout << std::endl;
    }
}

