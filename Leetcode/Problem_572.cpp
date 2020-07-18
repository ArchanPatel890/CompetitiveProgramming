#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) {
            return !t;
        }

        vector<TreeNode*> dfs;
        dfs.push_back(s);
        while (!dfs.empty()) {
            auto curr = dfs.back();
            dfs.pop_back();
            if (checkSubtree(curr, t)) {
                return true;
            }
            if (curr->left) {
                dfs.push_back(curr->left);
            }
            if (curr->right) {
                dfs.push_back(curr->right);
            }
        }

        return false;
    }

    bool checkSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        }
        if (s && !t || !s && t) {
            return false;
        }

        return checkSubtree(s->left, t->left)
        && checkSubtree(s->right, t->right)
        && s->val == t->val;
    }
};
