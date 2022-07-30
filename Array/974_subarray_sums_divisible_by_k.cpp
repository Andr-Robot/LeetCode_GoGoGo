/*
 * Author: robot
 * Source : https://leetcode.cn/problems/subarray-sums-divisible-by-k/
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> pre_sum;
        int sum = 0;
        pre_sum.push_back(sum);
        for (auto a : nums) {
            sum += a;
            pre_sum.push_back(sum);
        }
        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i <= nums.size(); i++) {
            // 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
            int a = (pre_sum[i] % k + k) % k;
            // 统计在nums[i-1]结尾的存在多少个子数组符合要求
            if (mp.find(a) != mp.end()) {
                // 如果哈希表中存在 key 与当前前缀和模 k 的值相等时，将满足条件的 key 出现的次数，累加到结果中
                res += mp[a];
                mp[a]++;
            } else {
                mp[a] = 1;
            }
        }
        return res;
    }
};