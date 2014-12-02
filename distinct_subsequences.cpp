#include <string>
#include <vector>

using namespace std;

// 动态规划
// S长度为i, T长度为j
// W(i, j) = W(i-1, j-1) + W(i-1, j) when S[i] == T[j]
//         = W(i-1, j)               when S[i] != T[j]
int numDistinct(string S, string T) 
{
    int s_size = S.size();
    int t_size = T.size();

    if(t_size > s_size)
        return 0;

    vector<vector<int> > result(s_size+1, vector<int>(t_size+1, 0));

    for(int i=0; i<=s_size; i++)
        result[i][0] = 1;

    for(int i=1; i<=s_size; i++)
    {
        for(int j=1; j<=t_size; j++)
        {
            if(S[i-1] == T[j-1])
            {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
            else
            {
                result[i][j] = result[i-1][j];
            }
        }
    }

    return result[s_size][t_size];
}

