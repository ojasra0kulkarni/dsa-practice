#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

typedef long long ll;

class Solution {
public:
    Node* sortList(Node *head) {
        Node *h0 = new Node(-1);
        Node *t0 = h0;
        Node *h1 = new Node(-1);
        Node *t1 = h1;
        Node *h2 = new Node(-1);
        Node *t2 = h2;

        Node *curr = head;
        while (curr != nullptr) {
            if (curr->data == 0) {
                t0->next = curr;
                t0 = curr;
            } else if (curr->data == 1) {
                t1->next = curr;
                t1 = curr;
            } else { // curr->data == 2
                t2->next = curr;
                t2 = curr;
            }
            curr = curr->next;
        }

        if (h1->next != nullptr) {
            t0->next = h1->next;
        } else {
            t0->next = h2->next;
        }
        
        t1->next = h2->next; // connect 1s tail to 2s head
        t2->next = nullptr;

        Node *ans = h0->next;
        delete h0;
        delete h1;
        delete h2;
        return ans;
    }
};
