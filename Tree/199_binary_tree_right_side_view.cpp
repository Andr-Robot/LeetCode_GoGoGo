/*
 * Author: robot
 * Source : https://leetcode.cn/problems/binary-tree-right-side-view/
 */

#include <iostream>
#include <vector>
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

// 二叉树的右视图
class Solution {
   public:
    void helper(TreeNode *root, int depth) {
        if (root == nullptr) return;
        if (depth == res.size()) {
            res.push_back(root->val);
        }
        helper(root->right, depth + 1);
        helper(root->left, depth + 1);
    }
    vector<int> res;
    // 解法一：深度优先遍历
    // 每次到达新的一层的时候，将右侧的第一个节点加入到结果集中
    // 在递归调用的时候先访问右子树，在访问左子树，保证新的一层中最先访问的是右子树
    vector<int> rightSideView(TreeNode *root) {
        helper(root, 0);
        return res;
    }
    // 解法二：广度优先遍历【层次遍历】
    vector<int> rightSideView_v2(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) return result;
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
            int len = qu.size();
            for (int i = 0; i < len; i++) {
                TreeNode *cur = qu.front();
                qu.pop();
                if (cur->left) qu.push(cur->left);
                if (cur->right) qu.push(cur->right);
                if (len - 1 == i) res.push_back(cur->val);
            }
        }
        return result;
    }
};