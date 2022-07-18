/*
 * Author: robot
 * Source : https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
 */

#include <iostream>
#include <vector>
using namespace std;

// 最长连续递增序列
class Solution {
   public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        // 表示以nums[i]结尾的最大连续递增序列长度
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};