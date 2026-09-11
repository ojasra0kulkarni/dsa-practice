#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x, next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* h) {
        ListNode* p = nullptr;
        ListNode* c = h;
        while (c != nullptr) {
            ListNode* nxt = c->next;
            c->next = p;
            p = c;
            c = nxt;
        }
        return p;
    }

    bool isPalindrome(ListNode* h) {
        if (h == nullptr || h->next == nullptr) {
            return true;
        }

        ListNode* s = h;
        ListNode* f = h;
        ListNode* p = nullptr;

        while (f != nullptr && f->next != nullptr) {
            p = s;
            s = s->next;
            f = f->next->next;
        }

        ListNode* h1 = h;
        ListNode* h2 = s;

        if (f != nullptr) {
            h2 = s->next;
        }
        
        p->next = nullptr;

        ListNode* r2 = reverseList(h2);

        ListNode* l1 = h1;
        ListNode* l2 = r2;
        bool ans = true;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val != l2->val) {
                ans = false;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        return ans;
    }
};
