/*
 * Author: robot
 * Source : https://leetcode.cn/problems/4sum-ii/
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * @brief 四数相加 II
 * 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
 *  0 <= i, j, k, l < n
 *  nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 */
class Solution {
   public:
    // 两两合并，然后使用哈希表
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mmap;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int a = nums1[i] + nums2[j];
                if (mmap.find(a) != mmap.end()) {
                    mmap[a]++;
                } else {
                    mmap[a] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                int a = 0 - nums3[i] - nums4[j];
                if (mmap.find(a) != mmap.end()) {
                    res += mmap[a];
                }
            }
        }
        return res;
    }
};