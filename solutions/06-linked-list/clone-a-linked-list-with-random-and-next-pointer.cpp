#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#define pb push_back

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            Node* cp = new Node(curr->val);
            cp->next = curr->next;
            curr->next = cp;
            curr = cp->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next; // linking copied random to copied random
            }
            curr = curr->next->next;
        }

        Node* dummy = new Node(0);
        Node* newHead = dummy;
        curr = head;
        while (curr) {
            newHead->next = curr->next;
            curr->next = curr->next->next;

            newHead = newHead->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};
