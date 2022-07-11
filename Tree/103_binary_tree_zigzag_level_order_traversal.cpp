/*
 * Author: robot
 * Source : https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
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
// 103. 二叉树的锯齿形层序遍历
class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode *> qu;
        qu.push(root);
        int level = 1;
        while (!qu.empty()) {
            int len = qu.size();
            vector<int> sub;
            for (size_t i = 0; i < len; i++) {
                TreeNode *cur = qu.front();
                sub.push_back(cur->val);
                qu.pop();
                if (cur->left) qu.push(cur->left);
                if (cur->right) qu.push(cur->right);
            }
            // 翻转
            if (level % 2 == 0) reverse(sub.begin(), sub.end());
            res.push_back(sub);
            level++;
        }
        return res;
    }
};