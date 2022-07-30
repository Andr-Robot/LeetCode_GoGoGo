/*
 * Author: robot
 * Source : https://leetcode.cn/problems/3sum/
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 三数之和
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 */
class Solution {
   public:
    // 排序+for+双指针
    // 相当于将三数之和退化到两数之和来解决
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = 0 - nums[i];
            int s = i + 1;
            int e = nums.size() - 1;
            while (s < e) {
                if (nums[s] + nums[e] > target) {
                    while (s < e && nums[e] == nums[e - 1]) e--;
                    e--;
                } else if (nums[s] + nums[e] < target) {
                    while (s < e && nums[s + 1] == nums[s]) s++;
                    s++;
                } else {
                    res.push_back({nums[i], nums[s], nums[e]});
                    while (s < e && nums[s] == nums[s + 1]) s++;
                    while (s < e && nums[e] == nums[e - 1]) e--;
                    s++;
                    e--;
                }
            }
        }
        return res;
    }
};