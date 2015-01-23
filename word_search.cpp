#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool exist_helper(vector<vector<char> >& board, 
                  int row, 
                  int column, 
                  string& word, 
                  int start, 
                  vector<vector<int> >& visited);

bool exist(vector<vector<char> > &board, string word) 
{
    if(board.empty() || board[0].empty() || word.empty())
        return false;

    int row = board.size();
    int column = board[0].size();
    // The same letter cell may not be used more than once!
    vector<vector<int> > visited(row, vector<int>(column, 0));

    return exist_helper(board, 0, 0, word, 0, visited);
}

bool exist_helper(vector<vector<char> >& board, 
                  int row, 
                  int column, 
                  string& word, 
                  int start, 
                  vector<vector<int> >& visited)
{
    int row_size = board.size();
    int column_size = board[0].size();
    int word_size = word.size();

    if(start >= word_size)
        return true;

    // word的第一个字符
    if(start == 0)
    {
        for(int i=0; i<row_size; i++)
        {
            for(int j=0; j<column_size; j++)
            {
                if(word[start] == board[i][j])
                {
                    visited[i][j] = 1;

                    if(exist_helper(board, i, j, word, start+1, visited))
                        return true;

                    visited[i][j] = 0;
                }
            }
        }
    }
    else
    {
        int next_row[4] = {row-1, row+1, row, row};
        int next_column[4] = {column, column, column-1, column+1};

        for(int i=0; i<4; i++)
        {
            int row_ = next_row[i];
            int column_ = next_column[i];
            if(row_ >= 0 && row_ < row_size && column_ >= 0 && column_ < column_size)
            {
                if(visited[row_][column_] == 0 && word[start] == board[row_][column_])
                {
                    visited[row_][column_] = 1;

                    if(exist_helper(board, row_, column_, word, start+1, visited))
                        return true;

                    visited[row_][column_] = 0;
                }
            }
        }
    }

    return false;
}

