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
    vector<vector<int>> allTraversal(TreeNode* root) {
        vector<int> pre, in, post;
        if (!root) return {};

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1}); // {node, state} 1:pre, 2:in, 3:post

        while (!st.empty()) {
            auto p = st.top();
            st.pop();

            TreeNode* node = p.first;
            int s = p.second;

            if (s == 1) {
                pre.push_back(node->val);
                st.push({node, 2});
                if (node->left) st.push({node->left, 1});
            } else if (s == 2) {
                in.push_back(node->val);
                st.push({node, 3});
                if (node->right) st.push({node->right, 1});
            } else { // s == 3
                post.push_back(node->val);
            }
        }
        return {pre, in, post};
    }
};
