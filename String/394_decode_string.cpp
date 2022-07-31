/*
 * Author: robot
 * Source : https://leetcode.cn/problems/decode-string/
 */
#include <iostream>
#include <stack>
using namespace std;

/**
 * @brief 字符串解码
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 */
class Solution {
   public:
   // 通过两个栈来完成字符串解码，一个用于保存数字，一个用于保存字符串
    string decodeString(string s) {
        string res = "";
        int num = 0;
        stack<int> num_st;
        stack<string> str_st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                str_st.push(res);
                num_st.push(num);
                res = "";
                num = 0;
            } else if (s[i] == ']') {
                string tmp_str = str_st.top();
                str_st.pop();
                int n = num_st.top();
                num_st.pop();
                string append_str = "";
                for (int j = 0; j < n; j++) {
                    append_str = append_str + res;
                }
                res = tmp_str + append_str;
            } else if (isalpha(s[i])) {
                res = res + s[i];
            }
        }
        return res;
    }
};