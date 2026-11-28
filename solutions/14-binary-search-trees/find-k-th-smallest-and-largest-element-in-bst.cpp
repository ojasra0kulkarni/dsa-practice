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
    // Helper for kth smallest
    void dfsSmallest(TreeNode* node, int &k, int &ans) {
        if (!node) return;
        dfsSmallest(node->left, k, ans);
        if (k == 0) return;
        k--;
        if (k == 0) {
            ans = node->val;
            return;
        }
        dfsSmallest(node->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        dfsSmallest(root, k, ans);
        return ans;
    }

    // Helper for kth largest
    void dfsLargest(TreeNode* node, int &k, int &ans) {
        if (!node) return;
        dfsLargest(node->right, k, ans);
        if (k == 0) return;
        k--; // current node counted
        if (k == 0) {
            ans = node->val;
            return;
        }
        dfsLargest(node->left, k, ans);
    }

    int kthLargest(TreeNode* root, int k) {
        int ans = -1;
        dfsLargest(root, k, ans);
        return ans;
    }
};
