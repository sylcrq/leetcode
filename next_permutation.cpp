#include <algorithm>
#include <vector>

using namespace std;

void nextPermutation(vector<int> &num) 
{
    if(num.empty())
        return;

    // 从右向左, 找到第一个比前一个数大的数的位置
    int index = 0;
    for(size_t i=num.size()-1; i>0; i--)
    {
        if(num[i] > num[i-1])
        {
            index = i;
            break;
        }
    }

    // reverse 数组[index, end]
    int start = index;
    int end = num.size() - 1;
    while(start < end)
    {
        std::swap(num[start], num[end]);
        start++;
        end--;
    }

    // swap num[index-1]和数组[index, end]中第一个比num[index-1]大的数
    if(index > 0)
    {
        for(size_t i=index; i<num.size(); i++)
        {
            if(num[index-1] < num[i])
            {
                std::swap(num[index-1], num[i]);
                break;
            }
        }
    }

    return;
}

