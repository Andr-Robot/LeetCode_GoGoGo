/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/validate-binary-search-tree/
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
   private:
    TreeNode* pre = nullptr;

   public:
    // 结合二叉搜索树的性质：中序遍历是递增的
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);
        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
    // 迭代，中序遍历
    bool isValidBST_v2(TreeNode* root) {
        if (root == nullptr) return true;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur != nullptr) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if (pre != nullptr && pre->val >= cur->val) return false;
                pre = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};