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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;

        while(curr||!st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top();
                if(temp->right && temp->right!=prev){ // right child exists and not visited yet
                    curr = temp->right;
                } else { // right child is null or already visited
                    st.pop();
                    ans.push_back(temp->val);
                    prev = temp; // mark as visited
                }
            }
        }
        // cout<<ans.size()<<endl;
        return ans;
    }
};
