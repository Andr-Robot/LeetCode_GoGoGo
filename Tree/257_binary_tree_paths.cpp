/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/binary-tree-paths/
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>
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
    vector<string> res;
    vector<string> path;
    void backtracking(TreeNode* root) {
        path.push_back(to_string(root->val));
        if (root->left == nullptr && root->right == nullptr) {
            string path_str = "";
            for (size_t i = 0; i < path.size(); i++) {
                if (i == path.size() - 1) {
                    path_str = path_str + path[i];
                } else {
                    path_str = path_str + path[i] + "->";
                }
            }
            res.push_back(path_str);
            return;
        }
        if (root->left != nullptr) {
            backtracking(root->left);
            path.pop_back();
        }
        if (root->right != nullptr) {
            backtracking(root->right);
            path.pop_back();
        }
    }

   public:
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        path.clear();
        if (root == nullptr) return res;
        backtracking(root);
        return res;
    }
    // 迭代法：使用前序遍历
    vector<string> binaryTreePaths_v2(TreeNode* root) {
        vector<string> result;
        if (root == nullptr) return result;
        stack<TreeNode*> st;
        st.push(root);
        stack<string> path;
        path.push(to_string(root->val));
        while (!st.empty()) {
            TreeNode* cur = st.top();
            string cur_path = path.top();
            st.pop();
            path.pop();
            if (cur->left == nullptr && cur->right == nullptr) {
                result.push_back(cur_path);
            }
            if (cur->left) {
                st.push(cur->left);
                path.push(cur_path + "->" + to_string(cur->left->val));
            }
            if (cur->right) {
                st.push(cur->right);
                path.push(cur_path + "->" + to_string(cur->right->val));
            }
        }
        return result;
    }
};