/*
 * Author: robot
 * Source : https://leetcode.cn/problems/word-search/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 回溯的方式判断是否存在这个word
    bool helper(const vector<vector<char>>& board, vector<vector<bool>>& used, int i, int j, const string& word,
                int k) {
        // 停止递归的条件
        // 1. 当前字符和word中对应位置的不一致
        // 2. word字符串均被遍历完
        if (board[i][j] != word[k]) {
            return false;
        } else if (k == word.size() - 1) {
            // word中所有字符均可以在board中找到
            return true;
        }
        used[i][j] = true;
        // 分别向上下左右搜索
        if (i - 1 >= 0 && !used[i - 1][j]) {
            bool flag = helper(board, used, i - 1, j, word, k + 1);
            if (flag) {
                return true;
            }
        }
        if (i + 1 < board.size() && !used[i + 1][j]) {
            bool flag = helper(board, used, i + 1, j, word, k + 1);
            if (flag) {
                return true;
            }
        }
        if (j - 1 >= 0 && !used[i][j - 1]) {
            bool flag = helper(board, used, i, j - 1, word, k + 1);
            if (flag) {
                return true;
            }
        }
        if (j + 1 < board[0].size() && !used[i][j + 1]) {
            bool flag = helper(board, used, i, j + 1, word, k + 1);
            if (flag) {
                return true;
            }
        }
        // 周围都不存在符合要求的字符，则需要重新搜索
        used[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        // 表示当前位置是否已经被使用
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool flag = helper(board, used, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};