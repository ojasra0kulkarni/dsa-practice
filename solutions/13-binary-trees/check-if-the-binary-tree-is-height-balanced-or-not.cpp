#include <bits/stdc++.h>
using namespace std;

#define pb push_back

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
    int dfs(TreeNode* node) {
        if(!node) return 0;

        int l = dfs(node->left);
        if(l == -1) return -1;

        int r = dfs(node->right);
        if(r == -1) return -1;

        if(abs(l - r) > 1) return -1; // propagate unbalanced signal

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;

    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << (Solution().isBalanced(root) ? "true" : "false") << endl;
    return 0;
}
