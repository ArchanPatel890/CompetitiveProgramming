#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        ostringstream out;
        mySerialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data == "") return NULL;
        istringstream in(data);
        return myDeserialize(in);
    }

private:
	void mySerialize(TreeNode* root, ostringstream &out)
	{
		if(root == NULL) return;
		out << root->val << " ";
		mySerialize(root->left, out);
		mySerialize(root->right, out);
	}

	TreeNode* myDeserialize(istringstream &in)
	{
		string val;
		in >> val;
		TreeNode *root = new TreeNode(stoi(val));
		while(in >> val)
			buildTree(root, stoi(val));
		return root;
	}

	void buildTree(TreeNode* root, int n)
	{
		if(root->val > n)
		{
			if(root->left == NULL)
				root->left = new TreeNode(n);
			else
				buildTree(root->left, n);
		}
		else
		{
			if(root->right == NULL)
				root->right = new TreeNode(n);
			else
				buildTree(root->right, n);
		}
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));