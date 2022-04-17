/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/combination-sum-ii/
 */
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(const vector<int>& candidates, int target, int startindex) {
        if (0 == target) {
            res.push_back(path);
            return;
        }
        for (int i = startindex; i < candidates.size() && target - candidates[i] >= 0; i++) {
            // 同一个递归深度内，要对同一树层相同元素进行跳过，防止包含重复的组合
            // 如：candidates = [10,1,2,7,6,1,5]，排序后为[1,1,2,5,6,7,10], target = 8, 其中[1,2,5]和[2,1,5]
            if (i > startindex && candidates[i] == candidates[i-1]) {
                continue;
            }
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        sort(candidates.begin(), candidates.end()); // 先排序，方便后面做去重
        backtracking(candidates, target, 0);
        return res;
    }
};