/*
 * Author: robot
 * Date: 2022-04-10 10:40:24
 * Source : https://leetcode-cn.com/problems/house-robber-ii/
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int dp_helper(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[nums.size()];
    }
    int rob(vector<int>& nums) {
        if (0 == nums.size()) return 0;
        if (1 == nums.size()) return nums[0];
        // 可以分别考虑不包含尾部房间的场景和不包含头部房间的场景，最终取这两个的最大值即可
        vector<int> nums_1(nums.begin(), nums.end() - 1);
        int res_1 = dp_helper(nums_1);
        vector<int> nums_2(nums.begin() + 1, nums.end());
        int res_2 = dp_helper(nums_2);
        return max(res_1, res_2);
    }
    // 方法二： https://programmercarl.com/0213.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DII.html
    int rob_v2(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int result1 = robRange(nums, 0, nums.size() - 2);  // 情况二
        int result2 = robRange(nums, 1, nums.size() - 1);  // 情况三
        return max(result1, result2);
    }
    // 198.打家劫舍的逻辑
    int robRange(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};