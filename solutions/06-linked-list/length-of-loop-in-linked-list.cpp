#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int lengthOfLoop(ListNode *head) {
        ListNode *s = head;
        ListNode *f = head;

        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
            if (s == f) break; // loop detected
        }

        if (f == NULL || f->next == NULL) return 0; // no loop found

        int cnt = 1;
        f = f->next;
        while (f != s) {
            cnt++;
            f = f->next;
        }
        return cnt;
    }
};
