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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int ans=1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int sz=q.size();
            long long minIdxOnLevel=q.front().second;
            
            long long first=-1, last=-1;

            for(int i=0;i<sz;i++){
                auto p=q.front();
                q.pop();
                TreeNode* node=p.first;
                long long originalIdx=p.second;
                
                long long normalizedIdx=originalIdx-minIdxOnLevel;

                if(i==0) first=normalizedIdx;
                last=normalizedIdx;

                if(node->left){
                    q.push({node->left, 2*normalizedIdx+1});
                }
                if(node->right){
                    q.push({node->right, 2*normalizedIdx+2});
                }
            }
            ans=max(ans, (int)(last-first+1));
            // cout<<ans<<endl;
        }
        return ans;
    }
};
