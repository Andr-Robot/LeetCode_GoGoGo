/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/subsets/
 */
#include <vector>
using namespace std;
class Solution {
   private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(const vector<int>& nums, int startindex) {
        res.push_back(path);  // 收集子集，要放在终止添加的上面，否则会漏掉自己
        if (startindex == nums.size()) {  // 终止条件可以不加，因为到这儿的时候for循环也结束了
            return;
        }
        for (int i = startindex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        res.clear();
        backtracking(nums, 0);
        return res;
    }
};