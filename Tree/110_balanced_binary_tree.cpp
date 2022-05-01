/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/balanced-binary-tree/
 */

#include <iostream>
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
    // -1 表示已经不是平衡二叉树了，否则返回值是以该节点为根节点树的高度
    int helper(TreeNode *node) {
        if (node == nullptr) return 0;
        int left = helper(node->left);
        if (-1 == left) return -1;
        int right = helper(node->right);
        if (-1 == right) return -1;
        if (abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) return true;
        return helper(root) == -1 ? false : true;
    }
};