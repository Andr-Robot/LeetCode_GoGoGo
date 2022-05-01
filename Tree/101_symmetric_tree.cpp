/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/symmetric-tree/
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
   private:
    bool compare(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        } else if (!left && right) {
            return false;
        } else if (left && !right) {
            return false;
        } else if (left->val != right->val) {
            return false;
        }
        // 此时左右节点都不为空，且数值相同的情况
        // 然后进行递归，做下一层的判断
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;
    }

   public:
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return compare(root->left, root->right);
    }
    // 迭代——使用层次遍历
    bool isSymmetric_v2(TreeNode *root) {
        if (!root) {
            return true;
        }
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
            size_t s = qu.size();
            vector<int> tmp;
            for (size_t i = 0; i < s; i++) {
                TreeNode *cur = qu.front();
                qu.pop();
                if (cur != nullptr) {
                    tmp.push_back(cur->val);
                    qu.push(cur->left);
                    qu.push(cur->right);
                } else {
                    tmp.push_back(INT_MAX);
                }
            }
            if (tmp.size() > 1) {
                int i = 0;
                int j = tmp.size() - 1;
                while (i < j) {
                    if (tmp[i] != tmp[j]) {
                        return false;
                    }
                    i++;
                    j--;
                }
            }
        }
        return true;
    }
};