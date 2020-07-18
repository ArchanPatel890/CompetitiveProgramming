#include <iostream>  
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        
        int sum = 0;
        sumNumbers(root, 0, sum);
        return sum;
    }

    void sumNumbers(TreeNode* node, int num, int& sum) {
        // The node is a leaf
        int next = num * 10 + node->val;
        if (node->left) {
            sumNumbers(node->left, next, sum);
        }
        if (node->right) {
            sumNumbers(node->right, next, sum);
        }
        if (!node->left && !node->right) {
            sum += next;
        }
    }   
};