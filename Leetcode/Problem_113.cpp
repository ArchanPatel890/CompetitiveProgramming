#include <bits/stdc++.h>

using namespace std;

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> stack;
        pathSum(root, sum, 0, stack, ans);
        return ans;
    }

    void pathSum(TreeNode* node, int target, int curr, vector<int>& stack, vector<vector<int>>& ans) {
        if (!node) {
            return;
        }

        stack.push_back(node->val);
        if (!node->left && !node->right && target == curr + node->val) {
            ans.emplace_back(stack);
        }

        pathSum(node->left, target, curr + node->val, stack, ans);
        pathSum(node->right, target, curr + node->val, stack, ans);
        stack.pop_back();
    }
};
