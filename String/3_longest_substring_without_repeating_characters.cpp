/*
 * Author: robot
 * Source : https://leetcode.cn/problems/longest-substring-without-repeating-characters/
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    // 采用划动窗口法
    int lengthOfLongestSubstring(string s) {
        int res = INT_MIN;
        int i = 0;
        int len = s.size();
        if (0 == len) return 0;
        // 用于保存无重复字符子串，key是字符，value是对应index
        // index有助于遇到重复的时候更新哈希表
        unordered_map<char, int> sub_map;
        while (i < len) {
            if (sub_map.find(s[i]) != sub_map.end()) {
                // 当遇到重复的，则缓存当前最长长度；然后删除重复元素之前的所有元素，接着继续添加元素
                int idx = sub_map[s[i]];
                for (auto iter = sub_map.begin(); iter != sub_map.end();) {
                    if (iter->second <= idx) {
                        iter = sub_map.erase(iter);
                    } else {
                        iter++;
                    }
                }
            }
            sub_map[s[i]] = i;
            int cur_len = sub_map.size();
            // 当遍历完后需要更新当前的最长长度
            res = max(res, cur_len);
            i++;
        }
        return res;
    }
    // 对上面的代码做个精简
    int lengthOfLongestSubstring_v2(string s) {
        int res = INT_MIN;
        int i = 0;     // 右侧窗口下标
        int left = 0;  // 左侧窗口下标
        int len = s.size();
        if (0 == len) return 0;
        unordered_set<char> sub_set;
        while (i < len) {
            while (sub_set.find(s[i]) != sub_set.end()) {
                sub_set.erase(s[left]);
                left++;
            }
            sub_set.insert(s[i]);
            res = max(res, i - left + 1);
            i++;
        }
        return res;
    }
};