#include <algorithm>
#include <vector>

using namespace std;

void subsetsWithDup_helper(vector<vector<int> >& result, vector<int>& set, vector<int>& S, size_t step);

vector<vector<int> > subsetsWithDup(vector<int> &S)
{
    vector<int> sorted_S(S);
    std::sort(sorted_S.begin(), sorted_S.end());

    vector<vector<int> > result;
    vector<int> set;

    result.push_back(set);

    subsetsWithDup_helper(result, set, sorted_S, 0);

    return result;
}

void subsetsWithDup_helper(vector<vector<int> >& result, vector<int>& set, vector<int>& S, size_t step)
{
    if(step >= S.size())
        return;

    for(size_t i=step; i<S.size(); i++)
    {
        if(i > step && S[i] == S[i-1])  // Note: "i > step"
            continue;

        set.push_back(S[i]);
        result.push_back(set);

        // recursive 
        subsetsWithDup_helper(result, set, S, i+1);  // Note: "i+1"

        set.pop_back();
    }
}

