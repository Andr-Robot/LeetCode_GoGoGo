/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 */

#include <iostream>
#include <queue>
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
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right != nullptr) {
            // 当左子树为空，则此时需要在右子树中寻找最小值
            return minDepth(root->right) + 1;
        }
        if (root->left != nullptr && root->right == nullptr) {
            // 当右子树为空，则此时需要在左子树中寻找最小值
            return minDepth(root->left) + 1;
        }
        // 当左右子树都不为空，则取两个的最小值
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    // 迭代——层次遍历
    int minDepth_v2(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> qu;
        qu.push(root);
        int depth = 0;
        while (!qu.empty()) {
            size_t s = qu.size();
            depth++;
            for (size_t i = 0; i < s; i++) {
                TreeNode *cur = qu.front();
                qu.pop();
                if (cur->left != nullptr) qu.push(cur->left);
                if (cur->right != nullptr) qu.push(cur->right);
                // 只有当左右子树都为空，则说明遍历到了最近的叶子节点【最小深度】
                if (cur->left == nullptr && cur->right == nullptr) return depth;
            }
        }
        return depth;
    }
};