#include <deque>
#include <utility>  // std::pair
#include <vector>

using namespace std;

void solve_bfs(vector<vector<char> >& board, int row, int column);
//void print_two_dimensional_vector(vector<vector<char> >& board);

// UnSurrounded Regions必然有一个点在四边上
void solve(vector<vector<char>> &board) 
{
    if(board.empty() || board[0].empty())
        return;

    int row = board.size();
    int column = board[0].size();

    // check first and last row
    for(int i=0; i<column; i++)
    {
        solve_bfs(board, 0, i);
        solve_bfs(board, row-1, i);
    }

    // check first and last column
    for(int i=0; i<row; i++)
    {
        solve_bfs(board, i, 0);
        solve_bfs(board, i, column-1);
    }

    // set all 'O' to 'X'
    // set all 'Y' to 'O'
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            else if(board[i][j] == 'Y')
                board[i][j] = 'O';
        }
    }
}

// set unsurrounded regions from 'O' to 'Y'
void solve_bfs(vector<vector<char> >& board, int row, int column)
{
    if(board[row][column] == 'O')
    {
        int row_size = board.size();
        int column_size = board[0].size();

        // breadth-first search
        deque<pair<int, int> > my_queue;
        my_queue.push_back( std::make_pair(row, column) );
        board[row][column] = 'Y';

        while(!my_queue.empty())
        {
            int x = my_queue.front().first;
            int y = my_queue.front().second;

            my_queue.pop_front();

            // up
            if(x >= 1 && board[x-1][y] == 'O')
            {
                my_queue.push_back( std::make_pair(x-1, y) );
                board[x-1][y] = 'Y';
            }
            // down
            if(x < (row_size-1) && board[x+1][y] == 'O')
            {
                my_queue.push_back( std::make_pair(x+1, y) );
                board[x+1][y] = 'Y';
            }
            // left
            if(y >= 1 && board[x][y-1] == 'O')
            {
                my_queue.push_back( std::make_pair(x, y-1) );
                board[x][y-1] = 'Y';
            }
            // right
            if(y < (column_size-1) && board[x][y+1] == 'O')
            {
                my_queue.push_back( std::make_pair(x, y+1) );
                board[x][y+1] = 'Y';
            }
        }
    }
}

