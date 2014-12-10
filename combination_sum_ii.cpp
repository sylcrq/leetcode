#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void combinationSum2_helper(vector<int>& num, size_t start, int target, 
                            vector<int>& solution, int sum, 
                            vector<vector<int> >& result);

vector<vector<int> > combinationSum2(vector<int> &num, int target) 
{
    vector<vector<int> > result;
    vector<int> solution;

    if(num.empty() || target <= 0)
        return result;

    vector<int> sorted_num(num);
    // sort
    std::sort(sorted_num.begin(), sorted_num.end());

    combinationSum2_helper(sorted_num, 0, target, solution, 0, result);

    return result;
}

void combinationSum2_helper(vector<int>& num, size_t start, int target, 
                            vector<int>& solution, int sum, 
                            vector<vector<int> >& result)
{
    //if(start >= num.size())
    //    return;

    for(size_t i=start; i<num.size(); i++)
    {
        if(num[i] + sum > target)
        {
            break;
        }
        else if(num[i] + sum == target)
        {
            solution.push_back(num[i]);
            result.push_back(solution);
            solution.pop_back();
        }
        else
        {
            solution.push_back(num[i]);
            combinationSum2_helper(num, i+1, target, solution, sum+num[i], result);
            solution.pop_back();
        }
        
        // Note: 去除重复
        while(i < num.size()-1 && num[i] == num[i+1]) i++;
    }
}

