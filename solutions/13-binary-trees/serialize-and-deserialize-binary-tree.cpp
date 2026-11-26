#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void ser(TreeNode* node, stringstream& ss){
        if(!node){
            ss << "# ";
            return;
        }
        ss << node->val << " ";
        ser(node->left, ss);
        ser(node->right, ss);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        ser(root, ss);
        return ss.str();
    }

    TreeNode* deser(queue<string>& q){
        string s = q.front();
        q.pop();

        if(s == "#") return NULL;

        TreeNode* node = new TreeNode(stoi(s));
        node->left = deser(q);
        node->right = deser(q);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
        queue<string> q;
        while(getline(ss, s, ' ')) {
            if(!s.empty()) q.push(s);
        }
        
        return deser(q);
    }
};

// tiny main
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution sol;
    string s = sol.serialize(root);
    cout << s << endl;
    
    return 0;
}
