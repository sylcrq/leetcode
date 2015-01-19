#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Two Pointers
vector<vector<int> > fourSum(vector<int> &num, int target) 
{
    vector<vector<int> > result;
    int size = num.size();

    if(num.empty() || size < 4)
        return result;

    // sort
    std::sort(num.begin(), num.end());

    for(int i=0; i<=size-4; i++)
    {
        // 去重
        if(i > 0 && num[i] == num[i-1])
            continue;

        for(int j=i+1; j<=size-3; j++)
        {
            // 去重
            if(j > (i+1) && num[j] == num[j-1])
                continue;

            int start = j+1;
            int end = size-1;

            while(start < end)
            {
                if( (num[start] + num[end]) == (target - num[i] - num[j]) )
                {
                    // 去重
                    if(start > (j+1) && num[start] == num[start-1])
                    {
                        start++;
                        continue;
                    }
                    // 去重
                    if(end < (size-1) && num[end] == num[end+1])
                    {
                        end--;
                        continue;
                    }

                    vector<int> solution;
                    solution.push_back(num[i]);
                    solution.push_back(num[j]);
                    solution.push_back(num[start]);
                    solution.push_back(num[end]);
                    
                    result.push_back(solution);

                    start++;
                    end--;
                }
                else if( (num[start] + num[end]) > (target - num[i] - num[j]) )
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
    }

    return result;
}

