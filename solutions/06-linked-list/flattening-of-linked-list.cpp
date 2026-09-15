#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
public:
    Node* mergeTwoLists(Node* a, Node* b) {
        Node* temp = new Node(0); // dummy head
        Node* res = temp;

        while(a && b) {
            if(a->data < b->data) {
                temp->bottom = a;
                a = a->bottom;
            } else {
                temp->bottom = b;
                b = b->bottom;
            }
            temp = temp->bottom;
        }

        if(a) temp->bottom = a;
        else temp->bottom = b;

        return res->bottom;
    }

    Node* flatten(Node* head) {
        if(!head || !head->next) return head;

        head->next = flatten(head->next);
        head = mergeTwoLists(head, head->next);

        return head;
    }
};
