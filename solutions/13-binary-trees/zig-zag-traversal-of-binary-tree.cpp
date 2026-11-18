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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> tmp;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                tmp.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(!ltr) reverse(tmp.begin(),tmp.end()); // reverse for odd levels
            ans.push_back(tmp);
            ltr = !ltr;
        }
        return ans;
    }
};
