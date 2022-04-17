/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/permutations-ii/
 */
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
   private:
    vector<int> path;
    vector<vector<int>> res;
    void backtacking(const vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  // 当前节点使用过，则不添加
            // 去重逻辑，由于我们是顺序访问，所以可以得到如下结论：
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;  // 当前层的当前节点和前一个节点相同，且前一个节点已经访问过，则不添加
            used[i] = true;
            path.push_back(nums[i]);
            backtacking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    // 方法二：可以不排序，使用unordered_set实现去重
    void backtacking_v2(const vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  // 当前节点使用过，则不添加
            if (uset.find(nums[i]) != uset.end()) continue;
            used[i] = true;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtacking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtacking(nums, used);
        // 方法二：
        // backtacking_v2(nums, used);
        return res;
    }
};