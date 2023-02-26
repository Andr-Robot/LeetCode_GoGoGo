/*
 * Author: robot
 * Source : https://leetcode.cn/problems/longest-valid-parentheses
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        // 动态规划法
        // dp[i] 代表以下标为i结尾时，最长的长度
        vector<int> dp(s.size(), 0);
        int res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    if (i >= 2) {
                        dp[i] = dp[i - 2] + 2;
                    } else {
                        dp[i] = 2;
                    }
                } else {
                    // 出现类似于"()(())"这种情况
                    if (dp[i - 1] < i && s[i - dp[i - 1] - 1] == '(') {
                        if (i - dp[i - 1] - 2 >= 0) {
                            dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                        } else {
                            dp[i] = dp[i - 1] + 2;
                        }
                    }
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};