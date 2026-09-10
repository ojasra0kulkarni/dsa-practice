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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* nxt=nullptr;
        
        while(curr!=nullptr){
            nxt=curr->next;
            curr->next=prev; // reverse the link
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
};
