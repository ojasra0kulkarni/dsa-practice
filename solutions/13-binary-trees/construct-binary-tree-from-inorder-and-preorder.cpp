#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define pb push_back

class Solution {
public:
    unordered_map<int,int> mp; 
    
    TreeNode* build(vector<int>& pre, vector<int>& in, int ps, int pe, int is, int ie) {
        if(ps > pe || is > ie) return nullptr;
        
        int val = pre[ps];
        TreeNode* root = new TreeNode(val);
        
        int idx = mp[val];
        int cnt = idx - is; // count of nodes in left subtree
        
        root->left = build(pre, in, ps + 1, ps + cnt, is, idx - 1);
        root->right = build(pre, in, ps + cnt + 1, pe, idx + 1, ie);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        for(int i=0;i<n;i++) mp[in[i]]=i;
        
        return build(pre, in, 0, n - 1, 0, n - 1);
        
    }
};
