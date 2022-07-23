/*
 * Author: robot
 * Source : https://leetcode.cn/problems/increasing-triplet-subsequence/
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 递增的三元子序列
 * 给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。
 * 如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
 */
class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        // 维持两个数，递增顺序，当第三个递增的数出现则认为成立
        int first = nums[0];
        int second = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > second) {
                return true;
            } else if (nums[i] > first) {
                second = nums[i];
            } else {
                // 更新最小值
                first = nums[i];
            }
        }
        return false;
    }
};