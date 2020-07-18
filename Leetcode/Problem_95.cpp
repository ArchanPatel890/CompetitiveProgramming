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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }

        vector<vector<vector<TreeNode*>>> memo(n+1, vector<vector<TreeNode*>>(n+1));

        return getTrees(1, n, memo);
    }

    vector<TreeNode*> getTrees(int l, int r, vector<vector<vector<TreeNode*>>>& memo) {
        if (l > r) {
            return { nullptr };
        }

        if (memo[l][r].size()) {
            return memo[l][r];
        }
        
        for (int i = l; i <= r; ++i) {
            auto left = getTrees(l, i-1, memo);
            auto right = getTrees(i+1, r, memo);
            for (auto nl : left) {
                for (auto nr : right) {
                    TreeNode* curr = new TreeNode(i, nl, nr);
                    memo[l][r].push_back(curr);
                }
            }
        }

        return memo[l][r];
    }
};
