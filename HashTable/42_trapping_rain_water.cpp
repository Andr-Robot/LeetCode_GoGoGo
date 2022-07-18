/*
 * Author: robot
 * Source : https://leetcode.cn/problems/trapping-rain-water/
 */
#include <iostream>
#include <vector>
using namespace std;

// 接雨水
class Solution {
   public:
    // 方法一：按列计算能存储多少水【这里需要知道当前列左右的最大值】，最后在累加。（会超时！）
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int trap(vector<int>& height) {
        int res = 0;
        // 首尾不需要接雨水
        for (size_t i = 1; i < height.size() - 1; i++) {
            int right_max = height[i];  // 右侧最大值
            for (int r = i + 1; r < height.size(); r++) {
                if (height[r] > right_max) right_max = height[r];
            }
            int left_max = height[i];   // 左侧最大值
            for (int l = i - 1; l >= 0; l--) {
                if (height[l] > left_max) left_max = height[l];
            }
            int h = min(left_max, right_max) - height[i];
            if (h > 0) res += h;
        }
        return res;
    }
    // 方法二：动态规划。可以提前缓存两侧最大值的，用空间换时间
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int trap(vector<int>& height) {
        // 首位不能接雨水
        if (height.size() <= 2) return 0;
        // 左侧最大值
        vector<int> left_max_vec(height.size());
        left_max_vec[0] = height[0];
        for (size_t i = 1; i < height.size(); i++) {
            left_max_vec[i] = max(left_max_vec[i - 1], height[i]);
        }
        // 右侧最大值
        vector<int> right_max_vec(height.size());
        right_max_vec[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            right_max_vec[i] = max(right_max_vec[i + 1], height[i]);
        }
        // 加和
        int res = 0;
        for (size_t i = 0; i < height.size(); i++) {
            int h = min(left_max_vec[i], right_max_vec[i]) - height[i];
            if (h > 0) res += h;
        }
        return res;
    }
};