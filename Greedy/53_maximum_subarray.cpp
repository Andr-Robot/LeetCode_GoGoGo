/*
 * Author: robot
 * Source : https://leetcode.cn/problems/maximum-subarray/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int count = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            }
            if (count < 0) { // 重置最大子序起始位置，因为遇到负数一定是拉低总和
                count = 0;
            }
        }
        return result;
    }
    // 基于动态规划
    // 这里需要注意不能直接返回dp数组的最后一个值
    int maxSubArray_v2(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);  // dp[i]表示包括i之前的最大连续子序列和
        dp[0] = nums[0];
        int result = dp[0];
        for (size_t i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};