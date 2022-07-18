/*
 * Author: robot
 * Source : https://leetcode.cn/problems/longest-increasing-subsequence/
 */

#include <iostream>
#include <vector>
using namespace std;

// 最长递增子序列
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        // dp[i]表示i之前包括i的以nums[i]结尾最长上升子序列的长度
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};