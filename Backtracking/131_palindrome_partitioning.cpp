/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/palindrome-partitioning/
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
   private:
    vector<string> path;
    vector<vector<string>> res;
    bool isPalindrome(string s, int start, int end) {
        int i = start;
        int j = end;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtracking(string s, int startindex) {
        if (startindex == s.size()) {
            res.push_back(path);
            return;
        }
        // startindex类似于切割线
        for (int i = startindex; i < s.size(); i++) {
            if (isPalindrome(s, startindex, i)) {  // 是回文子串
                // 获取[startIndex,i]在s中的子串
                string str = s.substr(startindex, i - startindex + 1);
                path.push_back(str);
                backtracking(s, i + 1);  // 寻找i+1为起始位置的子串
                path.pop_back();         // 回溯过程，弹出本次已经填在的子串
            }
        }
    }

   public:
    vector<vector<string>> partition(string s) {
        path.clear();
        res.clear();
        backtracking(s, 0);
        return res;
    }
};