/*
 * Author: robot
 * Source : https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
 */

#include <iostream>
#include <vector>
using namespace std;

// 最长递增子序列的个数
class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        // dp[i]表示i之前包括i的以nums[i]结尾最长上升子序列的长度
        vector<int> dp(nums.size(), 1);
        // cnt[i]表示到nums[i]为止的最长递增子序列个数
        vector<int> cnt(nums.size(), 1);
        int max_len = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;  // 说明最长递增子序列的长度增加了
                        cnt[i] = cnt[j];    // 长度增加，数量不变
                    } else if (dp[j] + 1 == dp[i]) {
                        // 最长递增子序列的长度并没有增加，但是出现了长度一样的情况，数量增加
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                res = cnt[i];
            } else if (dp[i] == max_len) {
                res += cnt[i];
            }
        }
        return res;
    }
};