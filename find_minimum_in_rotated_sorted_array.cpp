#include <algorithm>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    int mid = (start+end) / 2;

    // 处理没有rotate的情况
    if(nums[start] < nums[end])
        return nums[start];

    while(true) {
        mid = (start+end) / 2;

        if(mid == start || mid == end)
            break;

        if(nums[mid] > nums[start])
            start = mid;
        else
            end = mid;
    }

    return std::min(nums[start], nums[end]);
}

