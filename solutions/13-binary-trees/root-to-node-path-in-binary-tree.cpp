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
    bool solve(TreeNode* node, int x, vector<int>& path) {
        if (!node) {
            return false;
        }

        path.push_back(node->val);

        if (node->val == x) {
            return true;
        }

        if (solve(node->left, x, path) || solve(node->right, x, path)) {
            return true;
        }

        path.pop_back(); // backtrack
        return false;
    }

    vector<int> rootToNodePath(TreeNode* root, int x) {
        vector<int> ans;
        if (!root) return ans;
        solve(root, x, ans);
        return ans;
    }
};
