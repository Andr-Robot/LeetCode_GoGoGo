/*
 * Author: robot
 * Source : https://leetcode.cn/problems/minimum-window-substring
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool check(unordered_map<char, int>& cnt_map, unordered_map<char, int>& ori_map) {
        for (auto iter = ori_map.begin(); iter != ori_map.end(); iter++) {
            if (cnt_map[iter->first] < iter->second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        // 统计t中的字符以及其出现的次数
        unordered_map<char, int> ori_map;
        for (int i = 0; i < t.size(); i++) {
            ori_map[t[i]]++;
        }
        // 统计划动窗口中在t中存在的字符及其出现的次数
        unordered_map<char, int> cnt_map;
        int min_len = INT_MAX;
        // 最小长度的起点
        int res_l = -1;
        // 划动窗口的两侧
        int l = 0;
        int r = 0;
        while (r < s.size()) {
            if (ori_map.find(s[r]) != ori_map.end()) {
                cnt_map[s[r]]++;
            }
            // 从左侧进行删减
            while (l <= r && check(cnt_map, ori_map)) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    res_l = l;
                }
                if (ori_map.find(s[l]) != ori_map.end()) {
                    cnt_map[s[l]]--;
                }
                l++;
            }
            r++;
        }
        return res_l == -1 ? "" : s.substr(res_l, min_len);
    }
};