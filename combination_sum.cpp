#include <algorithm>
#include <vector>

using namespace std;

void combinationSum_helper(vector<vector<int> >& result, 
                           vector<int>& solution, 
                           vector<int>& candidates,
                           size_t start,
                           int target,
                           int sum);

vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
{
    vector<vector<int> > result;
    vector<int> solution;

    if(candidates.empty())
        return result;

    vector<int> sorted_candidates(candidates);
    std::sort(sorted_candidates.begin(), sorted_candidates.end());

    combinationSum_helper(result, solution, sorted_candidates, 0, target, 0);

    return result;
}

void combinationSum_helper(vector<vector<int> >& result, 
                           vector<int>& solution, 
                           vector<int>& candidates,
                           size_t start,
                           int target,
                           int sum)
{
    if(start >= candidates.size() || sum > target)
        return;

    if(sum == target)
    {
        result.push_back(solution);
        return;
    }

    for(size_t i=start; i<candidates.size(); i++)
    {
        if(i > 0)
        {
            // 去重
            if(candidates[i] == candidates[i-1])
                continue;
        }

        solution.push_back(candidates[i]);
        combinationSum_helper(result,
                              solution, 
                              candidates, 
                              i,  // Note !
                              target, 
                              sum + candidates[i]);
        solution.pop_back();
    }
}

