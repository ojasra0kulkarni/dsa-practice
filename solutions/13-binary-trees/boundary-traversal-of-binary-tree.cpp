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
private:
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }

    void addLeft(TreeNode* node, vector<int>& ans) {
        TreeNode* curr = node;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr->val);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addLeaves(TreeNode* node, vector<int>& ans) {
        if(!node) return;
        if(isLeaf(node)){
            ans.push_back(node->val);
            return;
        }
        addLeaves(node->left, ans);
        addLeaves(node->right, ans);
    }

    void addRight(TreeNode* node, vector<int>& ans) {
        vector<int> tmp;
        TreeNode* curr = node;
        while(curr){
            if(!isLeaf(curr)) tmp.push_back(curr->val);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i=tmp.size()-1;i>=0;i--) ans.push_back(tmp[i]); // add in reverse
    }

public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        if(!isLeaf(root)) ans.push_back(root->val);
        
        addLeft(root->left, ans);
        addLeaves(root, ans);
        addRight(root->right, ans);
        
        return ans;
    }
}
