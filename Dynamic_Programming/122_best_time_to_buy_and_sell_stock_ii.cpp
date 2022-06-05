/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 */
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] 表示第i天持有股票所得最多现金。
        // dp[i][1] 表示第i天不持有股票所得最多现金
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            // 分两种情况：1、前一天持有，且保持现状，即dp[i-1][0]；2、今天买入则昨天已经卖出了，即dp[i-1][1]-prices[i]
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // 分两种情况：1、前一天不持有，且保持现状，即dp[i-1][1]；2、今天不持有，即dp[i-1][0]+prices[i]
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
    // 空间复杂度优化
    int maxProfit_v2(vector<int>& prices) {
        // dp[i][0] 表示第i天持有股票所得最多现金。
        // dp[i][1] 表示第i天不持有股票所得最多现金
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            // 分两种情况：1、前一天持有，且保持现状，即dp[i-1][0]；2、今天买入则昨天已经卖出了，即dp[i-1][1]-prices[i]
            dp[i%2][0] = max(dp[(i-1)%2][0], dp[(i-1)%2][1]-prices[i]);
            // 分两种情况：1、前一天不持有，且保持现状，即dp[i-1][1]；2、今天不持有，即dp[i-1][0]+prices[i]
            dp[i%2][1] = max(dp[(i-1)%2][1], dp[(i-1)%2][0]+prices[i]);
        }
        return dp[(prices.size() - 1)%2][1];
    }
    // 贪心法
    // 局部最优：收集每天的正利润，全局最优：求得最大利润。
    int maxProfit_v3(vector<int>& prices) {
        int result = 0;
        for (size_t i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};