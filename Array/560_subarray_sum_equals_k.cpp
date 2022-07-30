/*
 * Author: robot
 * Source : https://leetcode.cn/problems/subarray-sum-equals-k/
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * @brief 和为 K 的子数组
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。
 */
class Solution {
   public:
    // 枚举法：会超时
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 考虑以 i 结尾和为 k 的连续子数组个数
            int msum = 0;
            for (int j = i; j >= 0; j--) {
                msum += nums[j];
                if (k == msum) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
    // 前缀和+哈希表
    // pre[j] - pre[i] = k，则说明[i,j]之间的数字加和为k，所以可以通过前缀和来统计结果
    // 使用哈希表缓存前缀和出现的次数，初始化map[0] = 1，最后可以通过统计哈希表中pre[j] - k出现的次数即可得到结果
    int subarraySum_v2(vector<int>& nums, int k) {
        unordered_map<int, int> mmap;
        mmap[0] = 1;
        int pre_sum = 0;
        int res = 0;
        for (auto a : nums) {
            pre_sum += a;
            if (mmap.find(pre_sum - k) != mmap.end()) {
                res += mmap[pre_sum - k];
            }
            if (mmap.find(pre_sum) != mmap.end()){
                mmap[pre_sum]++;
            } else {
                mmap[pre_sum] = 1;
            }
        }
        return res;
    }
};