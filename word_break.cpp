#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// 动态规划
bool wordBreak(string s, unordered_set<string> &dict) 
{
    if(s.empty())
        return false;

    int size = s.size();

    vector<bool> visited(size, false);

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j == i)
            {
                visited[i] = (dict.find(s.substr(0, j+1)) != dict.end());
            }
            else
            {
                visited[i] = (visited[j] && (dict.find(s.substr(j+1, i-j)) != dict.end()));
            }

            if(visited[i])
                break;
        }
    }

    return visited[size-1];
}

