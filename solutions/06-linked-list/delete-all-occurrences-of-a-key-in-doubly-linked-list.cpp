#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class Solution {
public:
    Node* deleteAllOccurrences(Node* head, int k) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == k) {
                Node* tmp = curr->next;

                if (curr->prev != nullptr) {
                    curr->prev->next = curr->next;
                } else {
                    head = curr->next;
                }

                if (curr->next != nullptr) {
                    curr->next->prev = curr->prev;
                }
                
                delete curr;
                curr = tmp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
// ^ submitted, accepted
