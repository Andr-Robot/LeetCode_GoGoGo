/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/permutations/
 */
#include <vector>
using namespace std;

class Solution {
   private:
    vector<int> path;
    vector<vector<int>> res;
    void bactracking(const vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            // 此时说明找到了一组
            res.push_back(path);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  // path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            bactracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        bactracking(nums, used);
        return res;
    }
};