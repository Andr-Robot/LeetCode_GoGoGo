/*
 * Author: robot
 * Source : https://leetcode.cn/problems/trim-a-binary-search-tree/
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
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == nullptr) return nullptr;
        // 当前节点值大于high，则在左子树中找符合要求的节点
        if (root->val > high) return trimBST(root->left, low, high);
        // 当前节点值小于low，则在右子树中找符合要求的节点
        if (root->val < low) return trimBST(root->right, low, high);
        // 对于符合要求的节点，按照原有的结构存储
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
    // 迭代法
    TreeNode *trimBST_v2(TreeNode *root, int low, int high) {
        if (root == nullptr) return nullptr;
        // 判断root是否符合要求
        while (root != nullptr && (root->val < low || root->val > high)) {
            if (root->val > high) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        // 当前root的值符合区间要求
        TreeNode *cur = root;
        while (cur != nullptr) {
            while (cur->left != nullptr && cur->left->val < low) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;
        while (cur != nullptr) {
            while (cur->right != nullptr && cur->right->val > high) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};