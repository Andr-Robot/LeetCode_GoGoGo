/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/sum-of-left-leaves/
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_sum = sumOfLeftLeaves(root->left);                                                  // 左
        int right_sum = sumOfLeftLeaves(root->right);                                                // 右
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {  // 中
            // 使用当前节点判断左子树节点是否为左叶子
            return root->left->val + left_sum + right_sum;
        } else {
            return left_sum + right_sum;
        }
    }
    // 方法二：迭代
    int sumOfLeftLeaves_v2(TreeNode* root){
        if (root == nullptr) return 0;
        stack<TreeNode*> st;
        st.push(root);
        int res = 0;
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur->left != nullptr && cur->left->left == nullptr && cur->left->right == nullptr) {
                res += cur->left->val;
            }
            if (cur->left) st.push(cur->left);
            if (cur->right) st.push(cur->right);
        }
        return res;
    }
};