#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

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
    TreeNode* recoverFromPreorder(string S) {
        unordered_map<int, TreeNode*> depthMap;

        int depth = 0;
        int n = S.size();
        int val = 0;
        for (int i = 0; i < n; ++i) {

            // Is a number
            if (S[i] >= '0' && S[i] <= '9') {
                val *= 10;
                val += S[i] - '0';

                // Is the last digit
                if (i == n-1 || S[i+1] == '-') {
                    auto node = new TreeNode(val);
                    if (!depth) {
                        depthMap[depth] = node;
                    }
                    else {
                        auto parent = depthMap[depth-1];
                        if (!parent->left) {
                            parent->left = node;
                        }
                        else {
                            parent->right = node;
                        }
                        depthMap[depth] = node;
                    }
                    
                    val = 0;
                    depth = 0;
                }
            }

            // Is a depth marker
            if (S[i] == '-') {
                ++depth;
            }
        }

        return depthMap[0];
    }
};
