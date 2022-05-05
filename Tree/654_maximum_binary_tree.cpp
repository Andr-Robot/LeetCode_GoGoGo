/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/maximum-binary-tree/
 */
#include <iostream>
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
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start > end || end >= nums.size()) return nullptr;
        int max_idx = 0;
        int max_val = INT_MIN;
        for (size_t i = start; i <= end; i++) {
            if (nums[i] > max_val) {
                max_val = nums[i];
                max_idx = i;
            }
        }
        TreeNode* root = new TreeNode(max_val);
        if (start == end) return root;
        // 根据max_idx划分子树
        root->left = helper(nums, start, max_idx - 1);
        root->right = helper(nums, max_idx + 1, end);
        return root;
    }

   public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) { return helper(nums, 0, nums.size() - 1); }
};