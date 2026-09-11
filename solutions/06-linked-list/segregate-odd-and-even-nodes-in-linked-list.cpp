#include <bits/stdc++.h>
using namespace std;

#define pb push_back

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* segregateEvenOdd(ListNode* head) {
        if(!head||!head->next) return head;

        ListNode* oh=new ListNode(-1);
        ListNode* eh=new ListNode(-1);

        ListNode* ot=oh;
        ListNode* et=eh;

        ListNode* curr=head;

        while(curr){
            if(curr->val%2!=0){
                ot->next=curr;
                ot=curr;
            } else {
                et->next=curr;
                et=curr;
            }
            curr=curr->next;
        }

        ot->next=eh->next;
        et->next=nullptr;

        return oh->next;
    }
};
