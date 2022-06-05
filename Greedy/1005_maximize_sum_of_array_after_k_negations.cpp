/*
 * Author: robot
 * Source : https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   private:
    static bool cmp(int a, int b) { return abs(a) > abs(b); }

   public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        // 先将负数全转成正数
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        // 当k还没有用完的时候，反转最小值
        // 这里需要区分k奇偶性，如果是奇数，则结果可能会反转，如果是偶数，则维持原值
        if (k % 2 == 1) {
            nums[nums.size() - 1] = -nums[nums.size() - 1];
        }
        int res = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            res += nums[i];
        }
        return res;
    }
};