/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/count-complete-tree-nodes/
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
    // 迭代：采用层次遍历的方式来统计节点数，O(n)
    int countNodes(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> qu;
        qu.push(root);
        int cnt = 0;
        while (!qu.empty()) {
            int s = qu.size();
            cnt += s;
            while (s > 0) {
                TreeNode *cur = qu.front();
                qu.pop();
                if (cur->left) qu.push(cur->left);
                if (cur->right) qu.push(cur->right);
                s--;
            }
        }
        return cnt;
    }
    // 递归：O(n)
    int countNodes(TreeNode *root) {
        if (root == nullptr) return 0;
        int left_num = countNodes(root->left);
        int right_num = countNodes(root->right);
        return left_num + right_num + 1;
    }
};