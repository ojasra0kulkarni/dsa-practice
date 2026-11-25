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
    // get height by traversing only left children
    int get_h(TreeNode* node){
        int h = 0;
        while(node){
            h++;
            node = node->left;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = get_h(root->left);
        int rh = get_h(root->right);

        if(lh==rh){
            return (1 << lh) + countNodes(root->right);
        }
        else {
            return (1 << rh) + countNodes(root->left);
        }
    }
};
