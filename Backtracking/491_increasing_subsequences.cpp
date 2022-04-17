/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/increasing-subsequences/
 */
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(const vector<int>& nums, int startindex) {
        if (path.size() > 1) {
            res.push_back(path);
            // 注意这里不要加return，要取树上的节点
        }
        unordered_set<int> uset;
        for (int i = startindex; i < nums.size(); i++) {
            // 在插入到path的时候就判断是否递增和是否重复
            if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        res.clear();
        backtracking(nums, 0);
        return res;
    }
};