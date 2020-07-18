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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTreeRecursive(p, q);
    }

    bool isSameTreeRecursive(TreeNode* p, TreeNode* q) {
        if (p && !q || !p && q) {
            return false;
        }
        if (!p && !q) {
            return true;
        }
        bool result = true;
        result &= isSameTreeRecursive(p->left, q->left);
        result &= p->val == q->val;
        result &= isSameTreeRecursive(p->right, q->right);
        return result;
    }
};