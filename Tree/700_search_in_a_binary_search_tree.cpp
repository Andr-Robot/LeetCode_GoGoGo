/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/search-in-a-binary-search-tree/
 */
#include <iostream>
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

class Solution {
   public:
    // 结合二叉搜索树的特性进行二分查找
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (val > root->val) {
            return searchBST(root->right, val);
        } else if (val == root->val) {
            return root;
        } else {
            return searchBST(root->left, val);
        }
    }
    // 迭代法
    TreeNode* searchBST_v2(TreeNode* root, int val) {
        while (root != NULL) {
            if (root->val > val)
                root = root->left;
            else if (root->val < val)
                root = root->right;
            else
                return root;
        }
        return NULL;
    }
};