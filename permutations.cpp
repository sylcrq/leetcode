//#include <algorithm>
#include <vector>

using namespace std;

void permute_recursive(vector<int>& num, vector<int>& visited, vector<int>& val, vector<vector<int> >& result);


vector<vector<int> > permute(vector<int> &num)
{
    vector<vector<int> > result;

    if(num.empty())
        return result;

    vector<int> visited(num.size(), 0);  // 记录num中已经排列过的数
    vector<int> val;  // 一种排列

    permute_recursive(num, visited, val, result);

    return result;
}

// 递归
void permute_recursive(vector<int>& num, vector<int>& visited, vector<int>& val, vector<vector<int> >& result)
{
    if(num.size() == val.size())
    {
        result.push_back(val);
        return;
    }

    for(size_t i=0; i<num.size(); i++)
    {
        if(visited[i] == 0)
        {
            val.push_back(num[i]);
            visited[i] = 1;

            permute_recursive(num, visited, val, result);

            visited[i] = 0;
            val.pop_back();
        }
    }

}

