/*
 * Author: robot
 * Source : https://leetcode.cn/problems/first-missing-positive/
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 缺失的第一个正数
class Solution {
public:
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 存在n个数，最极端的情况就是1~n，此时根据题意应该返回n+1
        // 剩下的情况就是确定1~n那个数字没有出现就是对应的结果
        // 可以在原数组的基础上标识出出现的数字，然后便可找到最终的结果
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                // 用负数标识出现过的数字
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
    // 时间复杂度：O(n)
    // 空间复杂度：O(n)
    int firstMissingPositive_v2(vector<int>& nums) {
        // 通过hashtable解决
        unordered_set<int> mset(nums.begin(), nums.end());
        for (int i = 1; i <= INT_MAX; i++) {
            if (mset.find(i) == mset.end()) {
                return i;
            }
        }
        return 1;
    }
};