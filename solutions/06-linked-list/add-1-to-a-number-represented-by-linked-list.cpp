#include <bits/stdc++.h>
using namespace std;

#define pb push_back

// Definition for singly-linked list.
struct Node {
    int data;
    Node *next;
    Node(int x) :data(x),next(nullptr){}
};

class Solution {
public:
    Node* reverse(Node* h) {
        Node* p=nullptr;
        Node* curr=h;
        Node* n=nullptr;
        while(curr) {
            n=curr->next;
            curr->next=p;
            p=curr;
            curr=n;
        }
        return p;
    }

    Node* addOne(Node* h) {
        Node* rh=reverse(h); // reversed head
        Node* tmp=rh;
        int c=1; // carry initialized to 1 for adding one
        Node* last=nullptr;

        while(tmp) {
            int s=tmp->data+c;
            tmp->data=s%10;
            c=s/10;
            last=tmp;
            tmp=tmp->next;
            if(c==0)break;
        }

        if(c>0) {
            last->next=new Node(c);
        }

        return reverse(rh);
    }
};
