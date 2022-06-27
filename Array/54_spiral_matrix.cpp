/*
 * Author: robot
 * Source : https://leetcode.cn/problems/spiral-matrix/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        vector<int> res;
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;
        while (left <= right && top <= bottom) {
            // 上侧，从左向右
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            // 右侧，从上向下
            for (int i = top + 1; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            if (left < right && top < bottom) {
                // 下侧，从右向左
                for (int i = right - 1; i > left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                // 左侧，从下向上
                for (int i = bottom; i > top; i--) {
                    res.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};