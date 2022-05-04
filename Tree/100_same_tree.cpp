/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/same-tree/
 */
#include <iostream>
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
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr)) {
            return false;
        } else if (p->val != q->val) {
            return false;
        }
        bool check_left = isSameTree(p->left, q->left);
        bool check_right = isSameTree(p->right, q->right);
        return check_left && check_right;
    }
};