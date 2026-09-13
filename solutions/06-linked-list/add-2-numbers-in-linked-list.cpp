#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // using dummy head
        ListNode* curr = dummy;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int temp = 0; // current digit sum
            if (l1) {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                temp += l2->val;
                l2 = l2->next;
            }
            temp += carry;

            carry = temp / 10;
            
            ListNode* tmp = new ListNode(temp % 10);
            curr->next = tmp;
            curr = curr->next;
        }
        return dummy->next;
    }
};
