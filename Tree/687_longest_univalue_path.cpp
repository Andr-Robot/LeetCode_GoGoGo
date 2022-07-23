/*
 * Author: robot
 * Source : https://leetcode.cn/problems/longest-univalue-path/
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
 * @brief 最长同值路径
 * 给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。
 * 这条路径可以经过也可以不经过根节点。
 * 两个节点之间的路径长度 由它们之间的边数表示。
 */
class Solution {
   private:
    int res;
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        // 如果存在左子节点和根节点同值，更新左最长路径；否则左最长路径为0
        if (root->left != nullptr && root->val == root->left->val) {
            left++;
        } else {
            left = 0;
        }
        // 如果存在右子节点和根节点同值，更新右最长路径;否则右最长路径为0
        if (root->right != nullptr && root->val == root->right->val) {
            right++;
        } else {
            right = 0;
        }
        res = max(res, left + right);
        return max(left, right);
    }

   public:
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        helper(root);
        return res;
    }
};