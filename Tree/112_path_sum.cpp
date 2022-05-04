/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/path-sum/
 */

#include <iostream>
#include <stack>
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
    bool backtracking(TreeNode *root, int targetSum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                return true;
            } else {
                return false;
            }
        }
        if (root->left) {
            if (backtracking(root->left, targetSum - root->val)) return true;
        }
        if (root->right) {
            if (backtracking(root->right, targetSum - root->val)) return true;
        }
        return false;
    }

   public:
    // 递归，回溯法
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return false;
        return backtracking(root, targetSum);
    }
    // 迭代
    bool hasPathSum_v2(TreeNode *root, int targetSum) {
        if (root == nullptr) return false;
        stack<TreeNode *> st;
        st.push(root);
        stack<int> num_cache;  // 缓存到当前节点时targetSum的状态，通过栈来模拟回溯
        num_cache.push(targetSum - root->val);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            int num = num_cache.top();
            num_cache.pop();
            if (cur->left == nullptr && cur->right == nullptr && 0 == num) {
                return true;
            }
            if (cur->left) {
                st.push(cur->left);
                num_cache.push(num - cur->left->val);
            }
            if (cur->right) {
                st.push(cur->right);
                num_cache.push(num - cur->right->val);
            }
        }
        return false;
    }
};
