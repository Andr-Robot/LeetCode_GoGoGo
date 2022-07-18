/*
 * Author: robot
 * Source : https://leetcode.cn/problems/palindromic-substrings/
 */
#include <iostream>
#include <vector>
using namespace std;

// 回文子串
class Solution {
   public:
    // 解法一：动态规划
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(n^2)
    // dp[i][j]: 表示[i,j]之间是回文子串则为true，否则为false
    // 1. 当s[i]!= s[j]，则为false
    // 2. 当s[i] == s[j]，则分情况讨论
    //  2.1 i == j，则为true
    //  2.2 i + 1 == j，则为true
    //  2.3 i + 1 < j，则受dp[i + 1][j - 1]的影响
    int countSubstrings(string s) {
        int res = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        res++;
                    } else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
    // 解法二：双指针
    // 由于回文子串是对称的，那么中间位置只会有两种情况
    // 1. 一个字符【长度为奇数】
    // 2. 两个字符【长度为偶数】
    // 所以可以分别以【当前位置】向两边扩充和以【当前和下一个】一起向两边扩充，统计回文子串的个数
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int checkLoop(const string &s, int i, int j) {
        int res = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
            res++;
        }
        return res;
    }
    int countSubstrings_v2(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += checkLoop(s, i, i);
            res += checkLoop(s, i, i + 1);
        }
        return res;
    }
};