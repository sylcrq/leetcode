#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) 
{
    vector<vector<int> > result;

    if(num.empty())
        return result;

    vector<int> sorted_num(num);
    std::sort(sorted_num.begin(), sorted_num.end());  // 排序

    for(size_t i=0; i<sorted_num.size(); i++)
    {
        if(i > 0)
        {   // Note: 去重
            if(sorted_num[i] == sorted_num[i-1])
                continue;
        }

        size_t start = i + 1;
        size_t end = sorted_num.size() - 1;

        int target = 0 - sorted_num[i];

        // Two Pointers
        while(start < end)
        {
            if(sorted_num[start] + sorted_num[end] == target)
            {
                vector<int> triplet;

                triplet.push_back(sorted_num[i]);
                triplet.push_back(sorted_num[start]);
                triplet.push_back(sorted_num[end]);

                result.push_back(triplet);

                do {
                    start++;
                }
                while(start < end && sorted_num[start] == sorted_num[start-1]);

                do {
                    end--;
                }
                while(start < end && sorted_num[end] == sorted_num[end+1]);
            }
            else if(sorted_num[start] + sorted_num[end] < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    return result;
}

