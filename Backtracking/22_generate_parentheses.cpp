/*
 * Author: robot
 * Source : https://leetcode.cn/problems/generate-parentheses/
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 括号生成
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 */
class Solution {
    private:
     vector<string> res;
     string path;
     void helper(int n, int left, int right) {
        if (path.size() == 2 * n) {
            res.push_back(path);
            return;
        }
        // 优先处理左括号
        if (left < n) {
            path.push_back('(');
            helper(n, left + 1, right);
            path.pop_back();
        }
        if (right < left) {
            path.push_back(')');
            helper(n, left, right + 1);
            path.pop_back();
        }
     }

    public:
     // 回溯法
     // 可以看做是组合问题，是带有限制条件的
     // 如果左括号数量不大于 n，我们可以放一个左括号。如果右括号数量小于左括号的数量，我们可以放一个右括号。
     vector<string> generateParenthesis(int n) {
        res.clear();
        path = "";
        helper(n, 0, 0);
        return res;
     }
};