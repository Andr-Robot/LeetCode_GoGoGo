/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
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

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == NULL) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q); // 左
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // 右
        if (left != NULL && right != NULL)
            return root;
        else if (left == NULL && right != NULL)
            return right;
        else if (left != NULL && right == NULL)
            return left;
        else
            return NULL;
    }
};