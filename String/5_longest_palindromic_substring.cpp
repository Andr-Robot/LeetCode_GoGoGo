/*
 * Author: robot
 * Source : https://leetcode.cn/problems/longest-palindromic-substring/
 */
#include <iostream>
#include <vector>
using namespace std;

// 最长回文子串
class Solution {
   public:
    // 动态规划
    // 存储最长回文子串的长度和其实位置，最终返回的时候对字符串进行截取即可
    string longestPalindrome(string s) {
        int max_len = 0;
        int start = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        if (j - i + 1 > max_len) {
                            max_len = j - i + 1;
                            start = i;
                        }
                    } else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        if (j - i + 1 > max_len) {
                            max_len = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
    // 解法二：双指针法
    // 返回起始和终止index
    vector<int> checkLoop(const string &s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return {i + 1, j - 1};
    }
    string longestPalindrome_v2(string s) {
        int max_len = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> res1 = checkLoop(s, i, i);
            if (max_len < res1[1] - res1[0] + 1) {
                max_len = res1[1] - res1[0] + 1;
                start = res1[0];
            }
            vector<int> res2 = checkLoop(s, i, i + 1);
            if (max_len < res2[1] - res2[0] + 1) {
                max_len = res2[1] - res2[0] + 1;
                start = res2[0];
            }
        }
        return s.substr(start, max_len);
    }
};