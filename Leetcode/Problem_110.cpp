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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        bool isBalanced = true;
        getHeight(root, isBalanced);
        return isBalanced;
    }

    int getHeight(TreeNode* curr, bool& isBalanced) {
        if (!curr) {
            return 0;
        }
        int left = getHeight(curr->left, isBalanced);
        int right = getHeight(curr->right, isBalanced);
        if (abs(left - right) > 1) {
            isBalanced = false;
        }

        return max(left, right) + 1;
    }
};
