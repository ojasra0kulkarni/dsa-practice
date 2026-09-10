#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head||!head->next) return nullptr;

        ListNode* s=head;
        ListNode* f=head;
        ListNode* p=nullptr; // node before s

        while(f&&f->next){
            p=s;
            s=s->next;
            f=f->next->next;
        }
        
        p->next=s->next;
        return head;
    }
};
