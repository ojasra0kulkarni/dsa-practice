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

typedef long long ll;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        map<int, map<int, multiset<int>>> mp; // col -> row -> vals
        queue<pair<TreeNode*, pair<int, int>>> q; // node -> {col, row}

        q.push({root, {0,0}});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            mp[x][y].insert(node->val);

            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
        }

        for(auto itCol : mp){
            vector<int> currCol;
            for(auto itRow : itCol.second){
                for(int val : itRow.second){
                    currCol.push_back(val);
                }
            }
            ans.push_back(currCol);
        }

        return ans;
    }
};
