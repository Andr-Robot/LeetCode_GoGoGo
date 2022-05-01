/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/invert-binary-tree/
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
    // 递归
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
    // 迭代
    TreeNode* invertTree_v2(TreeNode* root) {
        if (!root) return root;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            swap(cur->left, cur->right);
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        return root;
    }
};