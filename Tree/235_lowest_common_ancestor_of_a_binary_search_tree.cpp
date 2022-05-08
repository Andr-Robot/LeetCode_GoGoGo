/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */
#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    // 自上向下，前序遍历，结合二叉搜索树的特性（根节点大于左子树，小于右子树）
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root->val > p->val && root->val > q->val) {
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            if (left != NULL) return left;
        }
        if (root->val < p->val && root->val < q->val) {
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (right != NULL) return right;
        }
        return root;
    }
    // 自底向上，后序遍历
    TreeNode* lowestCommonAncestor_v2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == NULL) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;
        if (left != NULL) return left;
        return right;
    }
    // 迭代，结合二叉搜索树的特性
    TreeNode* lowestCommonAncestor_v3(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL) {
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            } else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            } else {
                break;
            }
        }
        return root;
    }
};