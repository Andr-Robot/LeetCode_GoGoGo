/*
 * Author: robot
 * Source : https://leetcode.cn/problems/regular-expression-matching
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        // 动态规划
        // dp[i][j] 表示s以i-1结尾是否与p以j-1结尾是否匹配
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        // 初始化
        dp[0][0] = true;  // 都是空
        // p为空
        for (int i = 1; i < s.size(); i++) {
            dp[i][0] = false;
        }
        // s为空
        for (int j = 2; j < p.size(); j++) {
            // * 可以表示任意个，那么可能是0个
            if ('*' == p[j - 1]) {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    // 当p[j-1]和s[i-1]相同时，则代表p[j-1]是字母，那么dp[i][j]=dp[i-1][j-1]
                    // 当p[j-1]时'.'，则dp[i][j]=dp[i-1][j-1]
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // p[j - 1]是'*'
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        // 此时需要考虑前面的是否能匹配，分为3种情况：
                        // 1. p[j-2]被删除，则当前状态依赖于s[i-1]和p[j-3]的状态，即dp[i][j] = dp[i][j-2]
                        // 2. p[j-2]被使用1次，则当前状态依赖于s[i-2]和p[j-3]的状态，即dp[i][j]=dp[i-1][j-2]
                        // 3.
                        // p[j-2]被使用多次，相当于先取出一个p[j-2]和s[i-1]抵消掉，然后继续重复对比，则当前状态依赖于s[i-2]和p[j-1]的状态，即dp[i][j]=dp[i-1][j]
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                    } else {
                        // 此时s[i-1]和p[j-2]不相等，则可以通过删除p[j-2]后再对比
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};