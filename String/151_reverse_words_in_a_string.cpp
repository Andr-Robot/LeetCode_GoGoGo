/*
 * Author: robot
 * Source : https://leetcode.cn/problems/reverse-words-in-a-string/
 */
#include <iostream>
using namespace std;

class Solution {
    // 翻转字符串
    void reverse(string &s, int i, int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    // 删除多余的空格
    void removeSpace(string &s) {
        int slow = 0;
        for (size_t i = 0; i < s.size(); i++) {
            // 遇到非空格就处理，即删除所有空格
            if (s[i] != ' ') {
                //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格
                if (slow != 0) {
                    s[slow] = ' ';
                    slow++;
                }
                // 补上该单词，遇到空格说明单词结束
                while (i < s.size() && s[i] != ' ') {
                    s[slow] = s[i];
                    slow++;
                    i++;
                }
            }
        }
        // slow的大小即为去除多余空格后的大小
        s.resize(slow);
    }

   public:
    // 从后向前遍历，使用双指针的方式
    // 空间复杂度O(n)
    string reverseWords(string s) {
        string res;
        int i = s.size() - 1;
        while (i >= 0) {
            // 过滤空格
            while (i >= 0 && ' ' == s[i]) {
                i--;
            }
            if (i < 0) break;
            // 通过双指针i,j来确定单词的下标范围
            int j = i;
            while (i >= 0 && s[i] != ' ') {
                i--;
            }
            // 将单词加到结果中
            int len = j - i;
            j = i + 1;
            while (len > 0) {
                res += s[j];
                j++;
                len--;
            }
            res += ' ';
        }
        // 切记，结果返回前需要删除结尾多余的空格
        return res.substr(0, res.size() - 1);
    }
    // 空间复杂度O(1)
    string reverseWords_v2(string s) {
        // 删除多余的空格
        removeSpace(s);
        // 整个字符串翻转
        reverse(s, 0, s.size() - 1);
        // 每个单词翻转
        int i = 0;
        int start = 0;
        while (i <= s.size()) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s, start, i - 1);
                start = i + 1;  // 下一个单词的开头
            }
            i++;
        }
        return s;
    }
};