#include <algorithm>
#include <vector>

using namespace std;

void subsets_helper(vector<vector<int> >& result, vector<int>& S, size_t start, vector<int> v);

vector<vector<int> > subsets(vector<int> &S) 
{
    vector<vector<int> > result;
    vector<int> v;

    if(S.empty()) return result;

    // sort
    vector<int> sorted_S(S);
    std::sort(sorted_S.begin(), sorted_S.end());

    result.push_back(v);
    subsets_helper(result, sorted_S, 0, v);

    return result;
}

void subsets_helper(vector<vector<int> >& result, vector<int>& S, size_t start, vector<int> v)
{
    if(start >= S.size()) return;

    for(size_t i=start; i<S.size(); i++)
    {
        v.push_back(S[i]);
        result.push_back(v);

        subsets_helper(result, S, i+1, v);

        v.pop_back();
    }
}
