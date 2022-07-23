/*
 * Author: robot
 * Source : https://leetcode.cn/problems/diameter-of-binary-tree/
 */
#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/**
 * @brief 二叉树的直径
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 */
class Solution {
   private:
    int res;
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;
        // 左子树深度
        int left = helper(root->left);
        // 右子树深度
        int right = helper(root->right);
        // 当前的最大路径长度
        res = max(res, left + right);
        // 返回以 root 为根节点的树的深度
        return max(left, right) + 1;
    }

   public:
    // 根据题目可以知道最长的直径不一定会经过根节点，所以是从任意节点到任意节点的路径
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }
};