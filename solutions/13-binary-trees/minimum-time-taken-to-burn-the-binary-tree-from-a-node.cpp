#include <bits/stdc++.h>
using namespace std;

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
    TreeNode* sNode = nullptr;
    map<TreeNode*, TreeNode*> par;

    void dfs(TreeNode* curr, int stVal) {
        if (!curr) return;

        if (curr->val == stVal) {
            sNode = curr;
        }

        if (curr->left) {
            par[curr->left] = curr;
            dfs(curr->left, stVal);
        }
        if (curr->right) {
            par[curr->right] = curr;
            dfs(curr->right, stVal);
        }
    }

    int minTime(TreeNode* root, int stVal) {
        if (!root) return 0;

        dfs(root, stVal);

        queue<TreeNode*> q;
        q.push(sNode);

        set<TreeNode*> vis;
        vis.insert(sNode);

        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            bool burnt = false; 
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && vis.find(curr->left) == vis.end()) {
                    burnt = true;
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if (curr->right && vis.find(curr->right) == vis.end()) {
                    burnt = true;
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if (par.count(curr) && vis.find(par[curr]) == vis.end()) {
                    burnt = true;
                    q.push(par[curr]);
                    vis.insert(par[curr]);
                }
            }
            if (burnt) ans++;
        }
        return ans;
    }
};
