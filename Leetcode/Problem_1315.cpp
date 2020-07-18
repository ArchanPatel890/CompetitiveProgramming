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
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) {
            return 0;
        }

        vector<TreeNode*> stack;
        stack.push_back(root);
        int total = 0;
        while(!stack.empty()) {
            auto curr = stack.back();
            stack.pop_back();
            if (curr->val % 2 == 0) {
                total += sumGrandchildren(curr);
            }
            if (curr->left) {
                stack.push_back(curr->left);
            }
            if (curr->right) {
                stack.push_back(curr->right);
            }
        }

        return total;
    }

    int sumGrandchildren(TreeNode* node) {
        int total = 0;
        if (node->left) {
            total += sumChildren(node->left);
        }
        if (node->right) {
            total += sumChildren(node->right);
        }
        return total;
    }

    int sumChildren(TreeNode* node) {
        int total = 0;
        total += node->left ? node->left->val : 0;
        total += node->right ? node->right->val : 0;
        return total;
    }
};
