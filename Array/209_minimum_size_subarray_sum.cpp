/*
 * Author: robot
 * Source : https://leetcode.cn/problems/minimum-size-subarray-sum/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;  // 划动窗口的起点
        int e = 0;  // 划动窗口的终点
        int res = INT_MAX;
        int sum = 0;
        while (e < nums.size()) {
            sum += nums[e];
            while (sum >= target) {
                int len = e - s + 1;
                res = min(res, len);
                sum -= nums[s];
                s++;
            }
            e++;
        }
        return res == INT_MAX ? 0 : res;
    }
};