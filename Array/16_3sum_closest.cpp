/*
 * Author: robot
 * Source : https://leetcode.cn/problems/3sum-closest/
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 最接近的三数之和
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 * 返回这三个数的和。
 * 假定每组输入只存在恰好一个解。
 */
class Solution {
   public:
    // 排序+for+双指针
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); i++) {
            int s = i + 1;
            int e = nums.size() - 1;
            while (s < e) {
                if (nums[s] + nums[e] + nums[i] == target) {
                    return target;
                }
                if (abs(nums[s] + nums[e] + nums[i] - target) < abs(res - target)) {
                    res = nums[s] + nums[e] + nums[i];
                }
                if (nums[s] + nums[e] + nums[i] > target) {
                    while (s < e && nums[e] == nums[e - 1]) e--;
                    e--;
                } else if (nums[s] + nums[e] + nums[i] < target) {
                    while (s < e && nums[s] == nums[s + 1]) s++;
                    s++;
                }
            }
        }
        return res;
    }
};