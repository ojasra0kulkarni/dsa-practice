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
    vector<int> bottomView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, int> mp; // hd -> node val
        queue<pair<TreeNode*, int>> q; // node, hd

        q.push({root, 0});

        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int d = q.front().second;
            q.pop();

            mp[d] = curr->val; // overwrite for bottom view

            if (curr->left) q.push({curr->left, d - 1});
            if (curr->right) q.push({curr->right, d + 1});
        }

        for (auto const& [hd, val] : mp) {
            ans.push_back(val);
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);

    Solution sol;
    vector<int> res = sol.bottomView(root);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
