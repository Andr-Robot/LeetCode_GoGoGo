/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */

#include <iostream>
#include <unordered_map>
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   private:
    unordered_map<int, int> inorder_map;
    TreeNode* helper(vector<int>& preorder, int in_s, int in_e, int pre_s, int pre_e) {
        if (in_s > in_e) return nullptr;
        int root_val = preorder[pre_s];
        TreeNode* root = new TreeNode(root_val);
        if (in_s == in_e) return root;
        int idx_of_root = inorder_map[root_val];
        int left_length = idx_of_root - in_s;
        root->left = helper(preorder, in_s, idx_of_root - 1, pre_s + 1, pre_s + left_length);
        root->right = helper(preorder, idx_of_root + 1, in_e, pre_s + left_length + 1, pre_e);
        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (size_t i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        return helper(preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }
};