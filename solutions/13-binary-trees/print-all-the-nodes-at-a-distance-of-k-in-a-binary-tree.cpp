#include <bits/stdc++.h>
using namespace std;

#define pb push_back

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    // dfs to populate parent map
    void buildPar(TreeNode* node, map<TreeNode*, TreeNode*>& par, TreeNode* p) {
        if (!node) return;
        par[node] = p;
        buildPar(node->left, par, node);
        buildPar(node->right, par, node);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> par;
        buildPar(root, par, NULL);

        queue<TreeNode*> q;
        map<TreeNode*, bool> vis;
        
        q.push(target);
        vis[target] = true;
        
        int d = 0;
        vector<int> ans;

        while(!q.empty()){
            if(d == k) break;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(par[curr] && !vis[par[curr]]){
                    q.push(par[curr]);
                    vis[par[curr]] = true;
                }
            }
            d++;
        }

        while(!q.empty()){
            ans.pb(q.front()->val);
            q.pop();
        }
        // cout<<ans.size()<<endl; 
        return ans;
    }
};
