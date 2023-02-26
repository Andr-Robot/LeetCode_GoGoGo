/*
 * Author: robot
 * Source : https://leetcode.cn/problems/unique-binary-search-trees-ii
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
    vector<TreeNode *> helper(int s, int e) {
        if (s > e) return {nullptr};
        vector<TreeNode *> res;
        // 遍历不同的根节点
        for (int i = s; i <= e; i++) {
            // 左子树，获取[s, i-1]组成的所有子树
            vector<TreeNode *> left_trees = helper(s, i - 1);
            // 右子树，获取[i+1, e]组成的所有子树
            vector<TreeNode *> right_trees = helper(i + 1, e);
            // 组合左右子树
            for (int l = 0; l < left_trees.size(); l++) {
                for (int k = 0; k < right_trees.size(); k++) {
                    TreeNode *cur_root = new TreeNode(i);
                    cur_root->left = left_trees[l];
                    cur_root->right = left_trees[k];
                    res.push_back(cur_root);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n) {
        if (n < 1) return {};
        return helper(1, n);
    }
};