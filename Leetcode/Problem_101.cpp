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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        if (!left && right || left && !right) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        
        return isSymmetric(left->right, right->left) 
            && isSymmetric(left->left, right->right);
    }
};