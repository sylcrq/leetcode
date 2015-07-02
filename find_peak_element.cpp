#include <vector>

using namespace std;

// 时间复杂度O(N)
int findPeakElement(vector<int>& nums) {
    if(nums.empty() || nums.size() == 1)
        return 0;

    int size = nums.size();

    if(nums[0] > nums[1])
        return 0;

    if(nums[size-1] > nums[size-2])
        return (size-1);

    size_t i = 1;
    for(; i<nums.size()-1; i++) {
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
            break;
    }

    return i;
}

// 从左向右遍历，如果nums[i] > nums[i+1]，那么nums[i]就是peak element
// 时间复杂度O(N)
int findPeakElement_ii(vector<int>& nums) {
    int end = nums.size() - 1;

    for(int i=0; i<end; i++) {
        if(nums[i] > nums[i+1])
            return i;
    }

    return end;
}

// 二分查找
// 如果nums[mid] > nums[mid+1]，那么左半部必然存在局部最大值peak element
int findPeakElement_iii(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;
    int mid = (start+end) / 2;

    while(start < end) {
        mid = (start+end) / 2;

        if(nums[mid] > nums[mid+1])
            end = mid;
        else
            start = mid+1;
    }

    return start;
}
