#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    map<int, int> m; // val -> inorder idx

    TreeNode* build(vector<int>& in, int is, int ie, vector<int>& post, int ps, int pe) {
        if(is>ie||ps>pe) return nullptr;

        int val = post[pe];
        TreeNode* root = new TreeNode(val);

        int idx = m[val]; // root index in inorder
        int len = idx - is; // length of left subtree

        root->left = build(in, is, idx-1, post, ps, ps+len-1);
        root->right = build(in, idx+1, ie, post, ps+len, pe-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        for(int i=0;i<n;i++) m[in[i]]=i; // map val to its index in inorder
        return build(in, 0, n-1, post, 0, n-1);
    }
};
