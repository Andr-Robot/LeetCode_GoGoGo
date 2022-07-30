/*
 * Author: robot
 * Source : https://leetcode.cn/problems/continuous-subarray-sum/
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> pre_sum;
        int sum = 0;
        pre_sum.push_back(sum);
        for (auto a : nums) {
            sum += a;
            pre_sum.push_back(sum);
        }
        unordered_set<int> mset;
        for (int i = 2; i <= nums.size(); i++) {
            mset.insert(pre_sum[i - 2] % k);
            if (mset.find(pre_sum[i] % k) != mset.end()) {
                return true;
            }
        }
        return false;
    }
};