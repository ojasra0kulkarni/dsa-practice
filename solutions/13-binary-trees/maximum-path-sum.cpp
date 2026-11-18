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

class Solution {
public:
    int solve(TreeNode* node, int& mx) {
        if (!node) return 0;
        
        int l = max(0, solve(node->left, mx)); // ignore negative path
        int r = max(0, solve(node->right, mx));
        
        mx = max(mx, node->val + l + r); 
        
        return node->val + max(l, r);
        
    }
    
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        solve(root, mx);
        return mx;
        
    }
};
