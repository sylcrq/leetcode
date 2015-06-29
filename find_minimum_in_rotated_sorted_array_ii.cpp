#include <algorithm>
#include <vector>

using namespace std;

// 最坏情况下的时间复杂度O(N)
int findMin_ii(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    int mid = (start + end) / 2;

    while(start < end) {
        mid = (start + end) / 2;

        // sorted array
        if(nums[start] < nums[end])
            return nums[start];

        if(nums[mid] > nums[start]) {
            start = mid;
        } else if(nums[mid] < nums[start]) {
            end = mid;
        } else {
            start++;
        }
    }

    //return std::min(nums[start], nums[end]);
    return nums[start];
}

