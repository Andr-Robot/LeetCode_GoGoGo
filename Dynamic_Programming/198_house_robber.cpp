/*
 * Author: robot
 * Date: 2022-04-10 10:40:24
 * Source : https://leetcode-cn.com/problems/house-robber/
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        // dp[i] 代表进入第i个房间能取得的最大值，这里房间是从1开始编号，对于i=0，表示不进入任何房间
        vector<int> dp(nums.size() + 1);
        dp[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // 将当前状态分为进入房间i，和不进入房间i，所以可以得到如下递推公式
            // 递推公式dp[i] = max(dp[i-1], dp[i-2] + value[i])
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }
        return dp[nums.size()];
    }
    // 方法二
    int rob_v2(vector<int>& nums) {
        if (0 == nums.size()) return 0;
        if (1 == nums.size()) return nums[0];
        // 考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};