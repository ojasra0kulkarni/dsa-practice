#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class Solution {
public:
    Node* ins(Node* head, int k, int d) {
        Node* node = new Node(d);
        // cout<<head->data<<endl;

        if (k == 1) {
            node->next = head;
            if (head) head->prev = node;
            return node;
        }

        Node* curr = head;
        int cnt = 1;
        while (curr && cnt < k - 1) { // traverse to k-1th node
            curr = curr->next;
            cnt++;
        }

        if (!curr) return head;

        Node* tmp = curr->next;

        curr->next = node;
        node->prev = curr;
        node->next = tmp;
        if (tmp) tmp->prev = node;

        return head;
    }
};
