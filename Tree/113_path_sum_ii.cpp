/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/path-sum-ii/
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   private:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(TreeNode *root, int targetSum) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                res.push_back(path);
            }
            return;
        }
        if (root->left) {
            backtracking(root->left, targetSum - root->val);
            path.pop_back();
        }
        if (root->right) {
            backtracking(root->right, targetSum - root->val);
            path.pop_back();
        }
        return;
    }

   public:
    // 回溯法
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        path.clear();
        res.clear();
        if (root == nullptr) return res;
        backtracking(root, targetSum);
        return res;
    }
};