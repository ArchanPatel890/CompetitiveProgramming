#include <bits/stdc++.h>

using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* curr;

    TreeNode* sortedListToBST(ListNode* head) {
        curr = head;
        int n = getSize(head);
        return getBST(0, n-1);
    }

    int getSize(ListNode* head) {
        int n = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            ++n;
        }
        return n;
    }

    TreeNode* getBST(int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int mid = (l + r) / 2;
        TreeNode* left = getBST(l, mid-1);
        TreeNode* node = new TreeNode(curr->val);
        curr = curr->next;
        TreeNode* right = getBST(mid+1, r);
        node->left = left;
        node->right = right;
        return node;
    }
};
