#include <vector>

using namespace std;

void combine_(int n, int k, int i, vector<int>& v, vector<vector<int> >& result);

vector<vector<int> > combine(int n, int k) 
{
    vector<vector<int> > result;
    vector<int> v;

    combine_(n, k, 1, v, result);

    return result;
}

void combine_(int n, int k, int i, vector<int>& v, vector<vector<int> >& result)
{
    if(v.size() == k)
    {
        result.push_back(v);
        return;
    }

    for(int j=i; j<=n; j++)
    {
        v.push_back(j);
        combine_(n, k, j+1, v, result);
        v.pop_back();
    }
}
