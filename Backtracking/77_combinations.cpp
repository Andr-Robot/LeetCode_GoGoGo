/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/combinations/
 */
#include <vector>
using namespace std;

class Solution {
   private:
    vector<int> path;         // 临时存储找到的组合
    vector<vector<int>> res;  // 最终结果
    void backtracking(int n, int k, int startindex) {
        // 终止条件
        if (path.size() == k) {
            // 保存结果
            res.push_back(path);
            return;
        }
        for (int i = startindex; i <= n; i++) {  // 控制树的横向遍历
            path.push_back(i);                   // 处理节点
            backtracking(n, k, i + 1);  // 递归：控制树的纵向遍历，注意下一层搜索要从i+1开始
            path.pop_back();            // 回溯，撤销处理的节点
        }
    }
    // 方法二：进行剪枝，减少计算次数
    void backtracking_v2(int n, int k, int startindex) {
        // 终止条件
        if (path.size() == k) {
            // 保存结果
            res.push_back(path);
            return;
        }
        // 搜索需要保证剩下的集合容量能够凑够k个数，所以使用 n - (k - path.size()) + 1 来进行剪枝
        for (int i = startindex; i <= n - (k - path.size()) + 1; i++) {  // 控制树的横向遍历
            path.push_back(i);                                           // 处理节点
            backtracking(n, k, i + 1);  // 递归：控制树的纵向遍历，注意下一层搜索要从i+1开始
            path.pop_back();            // 回溯，撤销处理的节点
        }
    }
   public:
    vector<vector<int>> combine(int n, int k) {
        path.clear();
        res.clear();
        backtracking(n, k, 1);
        return res;
    }
};