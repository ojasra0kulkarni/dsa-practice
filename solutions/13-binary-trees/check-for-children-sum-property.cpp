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
    bool isChildSum(TreeNode* node) {
        if(!node || (!node->left && !node->right)) return true; // base: null or leaf
        
        int sum=0;
        if(node->left) sum+=node->left->val;
        if(node->right) sum+=node->right->val;
        
        return (node->val==sum) && isChildSum(node->left) && isChildSum(node->right);
    }
};
