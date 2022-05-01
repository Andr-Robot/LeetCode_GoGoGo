
/*
 * Author: robot
 * Source : https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        for (size_t i = 0; i < root->children.size(); i++) {
            depth = max(depth, maxDepth(root->children[i]));
        }
        return depth + 1;
    }
};