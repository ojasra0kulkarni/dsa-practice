#include <bits/stdc++.h>
using namespace std;

#define pb push_back

// structure definition for a Doubly Linked List Node
struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

class Solution {
public:
    Node* deleteNode(Node*head, int k) {
        if(!head) return nullptr;

        Node*curr=head;
        int cnt=1;
        while(curr!=nullptr && cnt<k){
            curr=curr->next;
            cnt++;
        }

        // if k is invalid (e.g., k > length)
        if(!curr) return head;

        Node*p=curr->prev;
        Node*n=curr->next;

        if(p) p->next=n;
        if(n) n->prev=p;

        if(curr==head) head=n; // update head if first node deleted

        delete curr;
        return head;
    }
};
