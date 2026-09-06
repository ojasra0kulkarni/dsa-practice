#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int getLength(ListNode* head) {
        int cnt=0;
        ListNode* curr=head;
        while(curr!=nullptr){ // traverse list
            cnt++;
            curr=curr->next;
        }
        return cnt;
    }
};

int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    Solution s;
    cout<<s.getLength(head)<<endl;
    // cout<<s.getLength(nullptr)<<endl;
    return 0;
}
