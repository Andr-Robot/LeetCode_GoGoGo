/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

class Solution {
   private:
    unordered_map<int, int> inorder_map;
    TreeNode* helper(vector<int>& postorder, int in_s, int in_e, int post_s, int post_e) {
        if (in_s > in_e) return nullptr;
        int root_val = postorder[post_e];
        TreeNode* root = new TreeNode(root_val);
        if (in_s == in_e) return root;
        int idx_of_root = inorder_map[root_val];
        int left_length = idx_of_root - in_s;
        root->left = helper(postorder, in_s, idx_of_root - 1, post_s, post_s + left_length - 1);
        root->right = helper(postorder, idx_of_root + 1, in_e, post_s + left_length, post_e - 1);
        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (size_t i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        return helper(postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};