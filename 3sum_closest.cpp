#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

int threeSumClosest(vector<int> &num, int target) 
{
    if(num.empty() || num.size() < 3)
        return -1;

    int result = num[0] + num[1] + num[2];

    vector<int> sorted_num(num);
    std::sort(sorted_num.begin(), sorted_num.end());  // sort

    for(size_t i=0; i<sorted_num.size(); i++)
    {
        int start = i + 1;
        int end = sorted_num.size() - 1;

        // Two Pointers
        while(start < end)
        {
            int sum = sorted_num[start] + sorted_num[end] + sorted_num[i];

            if(sum == target)
            {
                return target;
            }
            else if(sum < target)
            {
                if(abs(sum - target) < abs(result - target))
                {
                    result = sum;
                }

                start++;
            }
            else
            {
                if(abs(sum - target) < abs(result - target))
                {
                    result = sum;
                }

                end--;
            }
        }
    }

    return result;
}

