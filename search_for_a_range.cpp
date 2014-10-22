#include <iostream>
#include <vector>

using namespace std;

// 平均时间复杂度为O(log n)
// 最差情况下会退化为O(n)
vector<int> searchRange(int A[], int n, int target) 
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    vector<int> range;

    int lower_bound = -1;
    int upper_bound = -1;

    // binary search
    while(start <= end)
    {        
        if(A[mid] > target)
        {
            end = mid - 1;
            mid = (start + end) / 2;
        }
        else if(A[mid] < target)
        {
            start = mid + 1;
            mid = (start + end) / 2;
        }
        else
        {
            int i = mid;
            while(i >= 0 && A[i] == target)
            {
                lower_bound = i;
                i--;
            }

            i = mid;
            while(i < n && A[i] == target)
            {
                upper_bound = i;
                i++;
            }

            break;
        }
    }

    range.push_back(lower_bound);
    range.push_back(upper_bound);

    return range;
}

// 两次binary search
// 时间复杂度为O(log n)
vector<int> searchRange_ii(int A[], int n, int target) 
{
    vector<int> range(2, -1);

    // find the lower bound
    int start = 0;
    int end = n - 1;

    while(start < end)
    {
        int mid = (start + end) / 2;
        if(A[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }

    if(A[start] != target)
        return range;

    int lower_bound = start;

    // find the upper bound
    start = lower_bound;
    end = n - 1;

    // Note: 当mid等于start时(两个元素)不能继续缩小范围
    while(start + 1 < end)
    {
        int mid = (start + end) / 2;
        if(A[mid] > target)
            end = mid - 1;
        else
            start = mid;
    }

    // 必然存在upper bound(大于等于lower bound)
    int upper_bound = lower_bound;

    while(end >= start)
    {
        if(A[end] == target)
        {
            upper_bound = end;
            break;
        }
        end--;
    }

    range[0] = lower_bound;
    range[1] = upper_bound;

    return range;
}

