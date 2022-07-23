/*
 * Author: robot
 * Source : https://leetcode.cn/problems/edit-distance/
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 编辑距离
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数。
 * 你可以对一个单词进行如下三种操作：
 *  插入一个字符
 *  删除一个字符
 *  替换一个字符
 */
class Solution {
   public:
    int minDistance(string word1, string word2) {
        // dp[i][j] 代表word1[i-1]和word2[j-1]的最小编辑距离
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 删除word1
                    // 增加word1
                    // 替换word1
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};