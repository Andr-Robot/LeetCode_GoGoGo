/*
 * Author: robot
 * Source : https://leetcode.cn/problems/two-sum/
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 两数之和
// 通过哈希表先存储所有数据的值，然后遍历去寻找符合要求的数对。其中需要注意的是：
// 1. 数组里面会有重复的数，这里保存最后一次出现的位置
// 2. 当target - nums[i]的到的结果可能会和当前的数值相同，此时需要确定数组中另一个存在和当前值相同的数
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        for (size_t i = 0; i < nums.size(); i++) {
            // 如果遇到两个相同的数，则保存的会是最后一次出现的位置
            num_map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int m = target - nums[i];
            if (num_map.find(m) != num_map.end() && num_map[m] != i) {
                return {i, num_map[m]};
            }
        }
        return {-1, -1};
    }
};