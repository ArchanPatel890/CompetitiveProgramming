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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> node_idx;
        int n = preorder.size();
        if (n == 0 || n != preorder.size()) {
            return nullptr;
        }

        for (int i = 0; i < n; ++n) {
            node_idx[inorder[i]] = i;
        }

        return buildTree(preorder, 0, n, inorder, 0, n, node_idx);
    }

    TreeNode* buildTree(vector<int>& preorder, int startp, int endp, vector<int>& inorder, int starti, int endi, map<int, int>& idx) {
        if (startp >= endp) {
            return nullptr;
        }
        TreeNode* curr = new TreeNode(preorder[startp]);
        int distance = idx[preorder[startp]] - starti;
        curr->left = buildTree(preorder, startp+1, startp+1+distance, inorder, starti, starti+distance, idx);
        curr->right = buildTree(preorder, startp+1+distance, endp, inorder, starti+distance+1, endi, idx);
        return curr;
    }
};
