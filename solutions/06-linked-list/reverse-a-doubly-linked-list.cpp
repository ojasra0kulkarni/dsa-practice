#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node *p, Node *n) : data(x), prev(p), next(n) {}
};

Node* reverseDLL(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* curr = head;
    Node* p = nullptr;
    Node* nxt = nullptr;

    while (curr != nullptr) {
        nxt = curr->next;

        curr->next = p;
        curr->prev = nxt;

        p = curr;
        curr = nxt;
    }

    return p;
    
}

// note to self: revisit the two pointer variant
