/*
 * Author: robot
 * Source : https://leetcode.cn/problems/longest-palindromic-subsequence/
 */
#include <iostream>
#include <vector>
using namespace std;
// 最长回文子序列
class Solution {
   public:
    // 动态规划
    // 该题和最长回文子串的区别是，子序列是允许不连续的
    // dp[i][j]: 表示[i,j]之间最长的回文子序列长度
    // 1. s[i] == s[j]，此时s[i]和s[j]均可加入，dp[i][j] = dp[i + 1][j - 1] + 2
    // 2. s[i] != s[j]，此时需要判断s[i]和s[j]那个加入可以取得最大值，dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
    // 通过上面的递推公式可以看到我们考虑的j - i >= 1的场景，所以在开始需要对i == j的场景进行初始化
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};