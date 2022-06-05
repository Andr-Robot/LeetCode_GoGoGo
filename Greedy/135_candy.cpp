/*
 * Author: robot
 * Source : https://leetcode.cn/problems/candy/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size(), 1);
        // 从前向后
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                res[i] = res[i - 1] + 1;
            }
        }
        // 从后向前
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                res[i] = max(res[i], res[i + 1] + 1);  // 这里可以令中间出现的极值，取一个最小值
            }
        }
        int sum = 0;
        for (size_t i = 0; i < res.size(); i++) {
            sum += res[i];
        }
        return sum;
    }
};