#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

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
    bool searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val==val) return true;
            if(val<root->val) root=root->left;
            else root=root->right;
        }
        return false;
    }
};
