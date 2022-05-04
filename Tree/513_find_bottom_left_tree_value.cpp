/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/find-bottom-left-tree-value/
 */

#include <iostream>
#include <queue>
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
    int max_depth = INT_MIN;
    int res = 0;
    // 递归，回溯法，根据题意这个是要找到深度最大的叶子节点
    void backtracking(TreeNode *root, int depth) {
        // 中
        if (root->left == nullptr && root->right == nullptr) {
            if (depth > max_depth) {
                max_depth = depth;
                res = root->val;
            }
            return;
        }
        // 左
        if (root->left != nullptr) {
            depth++;
            backtracking(root->left, depth);
            depth--;
        }
        // 右
        if (root->right != nullptr) {
            depth++;
            backtracking(root->right, depth);
            depth--;
        }
    }

   public:
    int findBottomLeftValue(TreeNode *root) {
        backtracking(root, 0);
        return res;
    }
    // 迭代：层次遍历，取最左端即可
    int findBottomLeftValue_v2(TreeNode *root) {
        int res = 0;
        if (root == nullptr) return res;
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
            int s = qu.size();
            for (size_t i = 0; i < s; i++) {
                TreeNode *cur = qu.front();
                qu.pop();
                if (0 == i) res = cur->val;
                if (cur->left) qu.push(cur->left);
                if (cur->right) qu.push(cur->right);
            }
        }
        return res;
    }
};