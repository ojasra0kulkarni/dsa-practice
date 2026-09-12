#include <bits/stdc++.h>
using namespace std;

// this struct is generally given
struct Node {
    int data;
    Node *prev;
    Node *next;
    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node *p, Node *n) : data(x), prev(p), next(n) {}
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        if(!head||!head->next) return head;

        Node* curr=head;
        while(curr!=nullptr&&curr->next!=nullptr){
            if(curr->data==curr->next->data){
                Node* dup=curr->next;
                curr->next=dup->next;
                if(dup->next) dup->next->prev=curr; // update prev ptr
            } else {
                curr=curr->next;
            }
        }
        return head;
    }
};
