/*
 * Author: robot
 * Source : https://leetcode.cn/problems/assign-cookies/
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        size_t i = 0;
        size_t j = 0;
        int cnt = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] > s[j]) {
                j++;
            } else {
                cnt++;
                i++;
                j++;
            }
        }
        return cnt;
    }
};