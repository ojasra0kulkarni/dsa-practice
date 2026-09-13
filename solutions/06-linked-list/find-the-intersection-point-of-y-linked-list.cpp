#include <bits/stdc++.h>
using namespace std;

#define pb push_back

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return NULL; // edge case

        ListNode *a=headA;
        ListNode *b=headB;

        while(a!=b){
            a=a->next;
            b=b->next;
            
            if(a==b) return a;

            if(!a) a=headB; // a done, switch to headB
            if(!b) b=headA; // b done, switch to headA
        }
        return a;
    }
};
