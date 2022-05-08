/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
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
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = INT_MAX;
        stack<TreeNode*> st;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while (!st.empty() || cur != nullptr) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if (pre != nullptr) {
                    int diff = abs(pre->val - cur->val);
                    if (diff < res) {
                        res = diff;
                    }
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
    }
};