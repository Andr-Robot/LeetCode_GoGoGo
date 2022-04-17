/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/combination-sum/
 */
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(const vector<int>& candidates, int target, int startindex) {
        // 终止条件
        if (0 == target) {
            // 符合要求，可加入结果集
            res.push_back(path);
            return;
        } else if (target < 0) {
            // 不符合要求，直接返回
            return;
        }
        for (int i = startindex; i < candidates.size(); i++) {
            path.push_back(candidates[i]); // 处理节点
            // 递归：由于是可重复取出，所以这里在下一层搜索需要从当前 i 开始
            backtracking(candidates, target - candidates[i], i);
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
    // 方法二：剪枝优化，这里需要传入的candidates是有序的
    void backtracking_v2(const vector<int>& candidates, int target, int startindex) {
        // 终止条件
        if (0 == target) {
            // 符合要求，可加入结果集
            res.push_back(path);
            return;
        }
        // 使用 target - candidates[i] > 0 来限制搜索次数，在调用前需要保证数组是递增的
        for (int i = startindex; i < candidates.size() && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);  // 处理节点
            // 递归：由于是可重复取出，所以这里在下一层搜索需要从当前 i 开始
            backtracking(candidates, target - candidates[i], i);
            path.pop_back();  // 回溯，撤销处理的节点
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        backtracking(candidates, target, 0);
        // 方法二
        // sort(candidates.begin(), candidates.end()); // 先排序，方便剪枝操作
        // backtracking_v2(candidates, target, 0);
        return res;
    }
};