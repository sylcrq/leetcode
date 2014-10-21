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

