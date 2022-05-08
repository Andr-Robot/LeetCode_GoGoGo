/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
 */
#include <iostream>
#include <stack>
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
   public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> st;
        TreeNode* pre = nullptr;
        int max_cnt = 0;
        int cnt = 0;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if (pre == nullptr) {
                    cnt = 1;
                } else if (pre->val == cur->val) {
                    cnt++;
                } else {
                    cnt = 1;
                }
                // 如果和最大值相同，放进res中
                if (cnt == max_cnt) res.push_back(cur->val);
                if (cnt > max_cnt) {
                    // 更新最大频率
                    max_cnt = cnt;
                    res.clear();
                    res.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
    }
};