/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/subsets-ii/
 */
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(const vector<int>& nums, int startindex) {
        res.push_back(path);
        if (startindex == nums.size()) {
            return;
        }
        for (int i = startindex; i < nums.size(); i++) {
            if (i > startindex && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        res.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
};