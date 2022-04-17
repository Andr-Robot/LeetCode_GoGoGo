/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/combination-sum-iii/
 */
#include <vector>
using namespace std;

class Solution {
   private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(int n, int k, int startindex) {
        if (0 == n && 0 == k) {
            res.push_back(path);
            return;
        }
        for (int i = startindex; i <= 9 && n - i >= 0 && k > 0; i++) {
            path.push_back(i);
            k--;
            backtracking(n - i, k, i + 1);
            path.pop_back();
            k++;
        }
    }

   public:
    vector<vector<int>> combinationSum3(int k, int n) {
        path.clear();
        res.clear();
        backtracking(n, k, 1);
        return res;
    }
};