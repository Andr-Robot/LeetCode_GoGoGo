/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 */
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < low) low = prices[i];  // 取最左最小价格
            res = max(res, prices[i] - low);       // 直接取最大区间利润
        }
        return res;
    }
    // 解法二：动态规划
    int maxProfit_v2(vector<int>& prices) {
        // dp[i][0] 表示第i天持有股票所得最多现金
        // dp[i][1] 表示第i天不持有股票所得最多现金
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
    // 解法三：动态规划，在解法二的基础上进行空间优化。
    // 通过递推公式可以知道只需要维持前后两天的状态，所以可以使用滚动数组来节约空间
    int maxProfit_v3(vector<int>& prices) {
        // dp[i][0] 表示第i天持有股票所得最多现金
        // dp[i][1] 表示第i天不持有股票所得最多现金
        // 这里使用size = 2的数组来保存前一天和当前天的状态
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);
        }
        return dp[(prices.size() - 1) % 2][1];
    }
};