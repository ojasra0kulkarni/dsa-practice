#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node* p, Node* n) : data(x), prev(p), next(n) {}
};

Node* createDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* nxt = new Node(arr[i]);
        curr->next = nxt;
        nxt->prev = curr;
        curr = nxt;
    }
    return head;
}
