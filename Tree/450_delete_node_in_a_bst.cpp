/*
 * Author: robot
 * Source : https://leetcode.cn/problems/delete-node-in-a-bst/
 */
#include <iostream>
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
    // 找右子树中最小值节点
    int getRightMini(TreeNode* node) {
        node = node->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->val;
    }
    // 找左子树中最大值节点
    int getLeftMax(TreeNode* node) {
        node = node->left;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                // 1. 叶子节点，则直接删除
                root = nullptr;
            } else if (root->right != nullptr) {
                // 2. 存在右子树，则用右子树中最小值替换当前节点的值，然后再删除右子树的最小值节点
                int mini_val = getRightMini(root);
                root->val = mini_val;
                root->right = deleteNode(root->right, mini_val);
            } else if (root->left != nullptr) {
                // 3. 仅存在左子树，则用左子树中最大值替换当前节点的值，然后再删除左子树的最大值节点
                int max_val = getLeftMax(root);
                root->val = max_val;
                root->left = deleteNode(root->left, max_val);
            }
        }
        return root;
    }
    // 方法二
    TreeNode* deleteNode_v2(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                // 1. 叶子节点，则直接删除
                root = nullptr;
            } else if (root->right == nullptr) {
                // 2. 右子树为空，则返回左子树
                root = root->left;
            } else if (root->left == nullptr) {
                // 3. 左子树为空，则返回右子树
                root = root->right;
            } else {
                // 4. 左右子树都不为空，则将删除节点的左子树放到删除节点的右子树的最小值节点的左孩子的位置
                TreeNode* cur = root->right;
                while (cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                root = root->right;
            }
        }
        return root;
    }
};