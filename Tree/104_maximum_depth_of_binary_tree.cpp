/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
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
   public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
    // 迭代——层次遍历
    int maxDepth_v2(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> qu;
        qu.push(root);
        int depth = 0;
        while (!qu.empty()) {
            size_t s = qu.size();
            depth++;
            for (size_t i = 0; i < s; i++) {
                TreeNode *cur = qu.front();
                qu.pop();
                if (cur->left != nullptr) qu.push(cur->left);
                if (cur->right != nullptr) qu.push(cur->right);
            }
        }
        return depth;
    }
};