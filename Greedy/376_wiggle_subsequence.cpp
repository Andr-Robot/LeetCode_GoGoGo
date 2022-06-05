/*
 * Author: robot
 * Source : https://leetcode.cn/problems/wiggle-subsequence/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 通过统计极值的个数来得到最终的结果
    int wiggleMaxLength(vector<int>& nums) {
        int pre_diff = 0; // 前一对的差值
        int cur_diff = 0; // 当前一对的差值
        int result = 1;
        for (size_t i = 0; i <nums.size() - 1; i++) {
            cur_diff = nums[i + 1] - nums[i];
            // pre_diff <= 0 && cur_diff > 0 代表出现新的峰值
            // pre_diff >= 0 && cur_diff < 0 代表出现新的谷底值
            if ((pre_diff <= 0 && cur_diff > 0) || (pre_diff >= 0 && cur_diff < 0)) {
                result++;
                pre_diff = cur_diff;
            }
        }
        return result;
    }
};