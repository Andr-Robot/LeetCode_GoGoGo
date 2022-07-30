/*
 * Author: robot
 * Source : https://leetcode.cn/problems/4sum/
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 四数之和
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 *  0 <= a, b, c, d < n
 *  a、b、c 和 d 互不相同
 *  nums[a] + nums[b] + nums[c] + nums[d] == target
 * 你可以按 任意顺序 返回答案 。
 */
class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > target && nums[i] >= 0 && target >= 0) break;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0 && target >= 0) break;
                // 防止越界
                long a = (long)target - nums[i] - nums[j];
                int s = j + 1;
                int e = nums.size() - 1;
                while (s < e) {
                    if (nums[s] + nums[e] > a) {
                        while (s < e && nums[e] == nums[e - 1]) e--;
                        e--;
                    } else if (nums[s] + nums[e] < a) {
                        while (s < e && nums[s] == nums[s + 1]) s++;
                        s++;
                    } else {
                        res.push_back({nums[i], nums[j], nums[s], nums[e]});
                        while (s < e && nums[s] == nums[s + 1]) s++;
                        while (s < e && nums[e] == nums[e - 1]) e--;
                        s++;
                        e--;
                    }
                }
            }
        }
        return res;
    }
};