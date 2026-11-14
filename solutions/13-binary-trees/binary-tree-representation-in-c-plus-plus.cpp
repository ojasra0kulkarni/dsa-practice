#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    // a simple inorder traversal to confirm tree representation
    void inorder(Node* node) {
        if(!node) return;
        inorder(node->left);
        // cout<<node->data<<" ";
        inorder(node->right);
    }
};
