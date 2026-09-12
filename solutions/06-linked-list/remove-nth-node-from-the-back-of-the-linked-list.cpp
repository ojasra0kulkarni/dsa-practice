#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode* fast = res;
        ListNode* slow = res;

        for(int i=0;i<n;i++) {
            fast = fast->next;
        }

        while(fast->next!=nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next; // skip the nth node

        return res->next;
    }
    
};
