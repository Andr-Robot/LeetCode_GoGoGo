/*
 * Author: robot
 * Source : https://leetcode.cn/problems/jump-game/
 */
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (1 == nums.size()) {
            return true;
        }
        for (int i = 0; i <= cover; i++) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
    // 如果一个位置能够到达，那么这个位置左侧所有位置都能到达
    bool canJump_v2(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i <= nums.size() - 1; i++) {
            if (i > k) {
                return false;
            }
            k = max(nums[i] + i, k);
        }
        return true;
    }
};