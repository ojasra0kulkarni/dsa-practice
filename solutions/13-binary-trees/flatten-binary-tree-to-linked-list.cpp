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

typedef long long ll;

class Solution {
public:
    TreeNode* prev = nullptr; // track last visited node

    void flatten(TreeNode* root) {
        if(!root) return;

        flatten(root->right);
        flatten(root->left);

        root->right=prev;
        root->left=nullptr;
        prev=root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root);

    TreeNode* curr = root;
    while(curr){
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;

    return 0;
}
