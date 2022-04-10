/*
 * Author: robot
 * Date: 2022-04-10 10:40:24
 * Source : https://leetcode-cn.com/problems/house-robber-iii/
 */

#include <unordered_map>
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
    // 解法一：使用记忆化递归
    unordered_map<TreeNode *, int> memory_map;
    int rob(TreeNode *root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return root->val;
        if (memory_map.find(root) != memory_map.end()) return memory_map[root];
        // 使用父节点
        int left_val = 0;
        int right_val = 0;
        if (root->left) {
            left_val = rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            right_val = rob(root->right->left) + rob(root->right->right);
        }
        int val1 = root->val + left_val + right_val;
        // 不使用父节点
        int val2 = rob(root->left) + rob(root->right);
        memory_map[root] = max(val1, val2);
        return max(val1, val2);
    }
    // 解法二：动态规划+递归
    vector<int> dp_helper(TreeNode* root) {
        // 这里使用长度为2的一维数组作为dp数组，其中dp[0]代表不使用该节点的最大值，dp[1]代表使用该节点的最大值
        if (root == nullptr) return {0, 0};
        vector<int> left_vec = dp_helper(root->left);
        vector<int> right_vec = dp_helper(root->right);
        // 使用当前节点，则不能使用子节点
        int val1 = root->val + left_vec[0] + right_vec[0];
        // 不使用当前节点，则可以使用子节点
        int val2 = max(left_vec[0], left_vec[1]) + max(right_vec[0], right_vec[1]);
        return {val2, val1};
    }
    int rob_v2(TreeNode* root) {
        vector<int> res = dp_helper(root);
        return max(res[0], res[1]);
    }
};