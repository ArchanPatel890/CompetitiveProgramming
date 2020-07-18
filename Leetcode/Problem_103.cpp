#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        bool rev = true;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            queue<TreeNode*> nextLevel;
            int n = level.size();
            vector<int> currLevel(n);
            for (int i = 0; i < n; ++i) {
                auto curr = level.front();
                level.pop();
                int idx = rev ? i : n - i - 1;
                currLevel[idx] = curr->val;
                if (curr->left) {
                    nextLevel.push(curr->left);
                }
                if (curr->right) {
                    nextLevel.push(curr->right);
                }
            }
            level = nextLevel;
            ans.push_back(currLevel);
            rev = !rev;
        }
        
        return ans;
    }
};
