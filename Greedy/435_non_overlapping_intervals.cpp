/*
 * Author: robot
 * Source : https://leetcode.cn/problems/non-overlapping-intervals/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    // 右侧排序，统计需要被删除的数量
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        int right = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); i++) {
            if (right > intervals[i][0]) {
                res++;
            } else {
                right = intervals[i][1];
            }
        }
        return res;
    }
};