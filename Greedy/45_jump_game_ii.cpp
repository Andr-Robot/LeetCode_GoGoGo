/*
 * Author: robot
 * Source : https://leetcode.cn/problems/jump-game-ii/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 对整个数组进行一次遍历即可
    // 在遍历至第i个元素时，首先更新前i个元素所能到达的最远位置cover
    // 然后判断当前位置的索引i是否超过当前跳跃次数所能到达的最远位置，若超过，则令当前跳跃次数自加1，并更新当前跳跃次数所能到达的最远位置
    int jump(vector<int>& nums) {
        int cover = 0;    // 接下来可以到达的最远距离下标
        int max_pos = 0;  // 当前能到的最大距离下标
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            cover = max(cover, i + nums[i]);  // 更新接下来可以到达最远距离的下标值
            if (i == max_pos) {               // 当到达当前的最远距离下标后，需要更新计数
                max_pos = cover;
                res++;
            }
        }
        return res;
    }
};