/*
 * Author: robot
 * Source : https://leetcode.cn/problems/maximal-square/
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 最大正方形
 *
 */
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (0 == matrix.size() || 0 == matrix[0].size()) return 0;
        // dp[i][j] 代表以i,j为右下角的只含1的正方形最大边长
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_len = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if ('1' == matrix[i][j]) {
                    if (0 == i || 0 == j) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    }
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }
        return max_len * max_len;
    }
};
