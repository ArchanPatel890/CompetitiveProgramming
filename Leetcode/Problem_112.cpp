#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 */
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        return hasPathSum(root, sum, 0);
    }

    bool hasPathSum(TreeNode* node, int target, int curr) {
        if (!node) {
            return false;
        }
        if (!node->left && !node->right) {
            return target == curr + node->val;
        }
        
        return hasPathSum(node->left, target, curr + node->val)
            || hasPathSum(node->right, target, curr + node->val);
    }
};
