/*
 * Author: robot
 * Source : https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 两个字符串的最小ASCII删除和
 * 给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。
 */
class Solution {
   public:
    int minimumDeleteSum(string s1, string s2) {
        // dp[i][j] 代表s1[i-1]s2[j-1]相等时所需删除字符的 ASCII 值的最小和
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        // s1不为空，s2为空时，需要依次删除s1的所有字符
        for (int i = 1; i <= s1.size(); i++) dp[i][0] = dp[i - 1][0] + s1[i - 1];
        // s1为空，s2不为空时，需要依次删除s2的所有字符
        for (int j = 1; j <= s2.size(); j++) dp[0][j] = dp[0][j - 1] + s2[j - 1];
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 取得删除s1[i - 1]或删除s2[j - 1]的最小值作为当前的最优解
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};