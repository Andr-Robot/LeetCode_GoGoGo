/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/restore-ip-addresses/
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> path;
    vector<string> res;
    // 判断字符串是否符合ip地址的要求
    bool check(const string &s) {
        if (s.size() > 1) {
            if (s.size() > 3 || stoi(s) > 255 || '0' == s[0]) {
                return false;
            }
        }
        return true;
    }
    void backtracking(string s, int startindex) {
        if (startindex == s.size() && 4 == path.size()) {
            string ip_str = "";
            for (size_t i = 0; i < 3; i++) {
                ip_str += path[i] + ".";
            }
            ip_str += path[3];
            res.push_back(ip_str);
            return;
        } else if (path.size() >= 4) {
            return;
        }
        for (int i = startindex; i < s.size(); i++) {
            string sub_s = s.substr(startindex, i - startindex + 1);
            if (check(sub_s)) {
                path.push_back(sub_s);
                backtracking(s, i + 1);
                path.pop_back();
            } else {
                // 不符合，则直接跳出本层循环
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        path.clear();
        res.clear();
        if (s.size() > 12) return res;
        backtracking(s, 0);
        return res;
    }
};
// 方法二：优化搜索范围
class Solution {
   private:
    vector<string> path;
    vector<string> res;
    bool check(const string &s) {
        if (s.size() > 1) {
            if (s.size() > 3 || stoi(s) > 255 || '0' == s[0]) {
                return false;
            }
        } else if (s.empty()) {
            return false;
        }
        return true;
    }
    void backtracking(string s, int startindex) {
        // 由于ip地址是有4个数字组成的，所以这里终止条件是在找到3个数字时
        if (3 == path.size()) {
            string sub_s = s.substr(startindex, s.size() - startindex + 1);
            if (check(sub_s)) {
                string ip_str = "";
                for (size_t i = 0; i < 3; i++) {
                    ip_str += path[i] + ".";
                }
                ip_str += sub_s;
                res.push_back(ip_str);
            }
            return;
        }
        for (int i = startindex; i < s.size(); i++) {
            string sub_s = s.substr(startindex, i - startindex + 1);
            if (check(sub_s)) {
                path.push_back(sub_s);
                backtracking(s, i + 1);
                path.pop_back();
            } else {
                // 不符合，则直接跳出本层循环
                break;
            }
        }
    }

   public:
    vector<string> restoreIpAddresses(string s) {
        path.clear();
        res.clear();
        if (s.size() > 12) return res;
        backtracking(s, 0);
        return res;
    }
};