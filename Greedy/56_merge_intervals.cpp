/*
 * Author: robot
 * Source : https://leetcode.cn/problems/merge-intervals/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    static bool cmp(vector<int> &a, vector<int> &b) { return a[0] < b[0]; }
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};