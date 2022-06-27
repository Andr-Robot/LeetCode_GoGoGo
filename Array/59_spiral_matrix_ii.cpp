/*
 * Author: robot
 * Source : https://leetcode.cn/problems/spiral-matrix-ii/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int num = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        while (left <= right && top <= bottom) {
            // 上侧，从左到右
            for (int i = left; i <= right; i++) {
                res[top][i] = num;
                num++;
            }
            // 右侧，从上到下
            for (int i = top + 1; i <= bottom; i++) {
                res[i][right] = num;
                num++;
            }
            // 下侧，从右到左
            for (int i = right - 1; i > left; i--) {
                res[bottom][i] = num;
                num++;
            }
            // 左侧，从下到上
            for (int i = bottom; i > top; i--) {
                res[i][left] = num;
                num++;
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};