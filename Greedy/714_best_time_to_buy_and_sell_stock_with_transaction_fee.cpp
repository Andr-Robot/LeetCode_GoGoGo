/*
 * Author: robot
 * Source : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = prices[0] + fee;
        int profit = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] + fee < buy) {
                // 记录低点买入的成本
                buy = prices[i] + fee;
            }
            else if (prices[i] > buy) {
                // 此处是中间过程统计利润
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return profit;
    }
};