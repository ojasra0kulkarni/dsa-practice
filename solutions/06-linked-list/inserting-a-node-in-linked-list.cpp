#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insert(ListNode* head, int x, int k) {
    ListNode* node = new ListNode(x);

    if (k == 1) { 
        node->next = head;
        return node;
    }

    ListNode* curr = head;
    for (int i = 1; i < k - 1; i++) { 
        if (curr == nullptr) return head; // pos too large, list too short
        curr = curr->next;
    }

    if (curr == nullptr) return head; 

    node->next = curr->next;
    curr->next = node;
    
    return head;
}
