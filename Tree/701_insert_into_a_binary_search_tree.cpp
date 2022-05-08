/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/
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
   private:
    void helper(TreeNode* root, int val) {
        if (root->val > val) {
            if (root->left == nullptr) {
                root->left = new TreeNode(val);
                return;
            } else {
                helper(root->left, val);
            }
        }
        if (root->val < val) {
            if (root->right == nullptr) {
                root->right = new TreeNode(val);
                return;
            } else {
                helper(root->right, val);
            }
        }
        return;
    }

   public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        helper(root, val);
        return root;
    }
    // 迭代法
    TreeNode* insertIntoBST_v2(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->val > val) {
                if (cur->left == nullptr) {
                    cur->left = new TreeNode(val);
                    break;
                }
                cur = cur->left;
            } else {
                if (cur->right == nullptr) {
                    cur->right = new TreeNode(val);
                    break;
                }
                cur = cur->right;
            }
        }
        return root;
    }
    // 迭代法，双指针
    TreeNode* insertIntoBST_v3(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* cur = root;
        TreeNode* parent = root;  // 这个很重要，需要记录上一个节点，否则无法赋值新节点
        while (cur != nullptr) {
            parent = cur;
            if (cur->val > val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        TreeNode* node = new TreeNode(val);
        if (val < parent->val)
            parent->left = node;  // 此时是用parent节点的进行赋值
        else
            parent->right = node;
        return root;
    }
};