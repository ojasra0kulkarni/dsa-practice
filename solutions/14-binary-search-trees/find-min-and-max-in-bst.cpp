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
    int findMin(TreeNode* root) {
        if(!root) return -1; // tree empty, return sentinel
        TreeNode* curr = root;
        while(curr->left) {
            curr = curr->left;
        }
        return curr->val;
    }

    int findMax(TreeNode* root) {
        if(!root) return -1; // tree empty, return sentinel
        TreeNode* curr = root;
        while(curr->right) {
            curr = curr->right;
        }
        return curr->val;
    }
};
