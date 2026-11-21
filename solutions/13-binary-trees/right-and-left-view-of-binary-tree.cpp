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
    void rightDFS(TreeNode* node, int lvl, vector<int>& ans) {
        if (!node) return;

        if (lvl == ans.size()) { // first node at this level
            ans.push_back(node->val);
        }
        rightDFS(node->right, lvl + 1, ans);
        rightDFS(node->left, lvl + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightDFS(root, 0, ans);
        // cout<<ans.size()<<endl;
        return ans;
    }

    void leftDFS(TreeNode* node, int lvl, vector<int>& ans) {
        if (!node) return;

        if (lvl == ans.size()) { // first node at this level
            ans.push_back(node->val);
        }
        leftDFS(node->left, lvl + 1, ans);
        leftDFS(node->right, lvl + 1, ans);
    }

    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        leftDFS(root, 0, ans);
        return ans;
    }
};
