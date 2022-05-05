/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/path-sum-iii/
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
   public:
    int res = 0;
    // 这里递归调用的参数使用long long是为了防止数值运算越界
    void helper(TreeNode *root, long long targetSum) {
        if (root == nullptr) return;
        if (0 == targetSum) {
            res += 1;
        }
        if (root->left != nullptr) helper(root->left, targetSum - root->left->val);
        if (root->right != nullptr) helper(root->right, targetSum - root->right->val);
    }
    // 使用双重递归，O(n^2)
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return res;
        helper(root, targetSum - root->val);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return res;
    }
};