#include <algorithm>
#include <vector>

using namespace std;

// 时间复杂度O(N),空间复杂度O(1)
// 动态规划
// dp[0] = nums[0] (当i=0)
// dp[1] = max(nums[0], nums[1]) (当i=1)
// dp[i] = max(dp[i-2]+nums[i], dp[i-1]) (当i>1)
int rob(vector<int>& nums) {
    if(nums.empty())
        return 0;

    if(nums.size() == 1)
        return nums[0];

    if(nums.size() == 2)
        return std::max(nums[0], nums[1]);

    int max = 0;
    int prev = std::max(nums[0], nums[1]);
    int pprev = nums[0];

    for(size_t i=2; i<nums.size(); i++) {
        max = std::max(pprev+nums[i], prev);
        pprev = prev;
        prev = max;
    }

    return max;
}

