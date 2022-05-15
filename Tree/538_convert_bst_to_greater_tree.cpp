/*
 * Author: robot
 * Source : https://leetcode.cn/problems/convert-bst-to-greater-tree/
 */
#include <iostream>
#include <vector>
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
    int sum = 0;

   public:
    // 反中序遍历（右中左）
    TreeNode *convertBST(TreeNode *root) {
        if (root == nullptr) return nullptr;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};