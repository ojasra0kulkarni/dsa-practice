#include <bits/stdc++.h>
using namespace std;

#define pb push_back

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
    int mx = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int l = dfs(node->left);
        int r = dfs(node->right);

        mx = max(mx, l + r);

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return mx;
    }
};
