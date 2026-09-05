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
    ListNode* construct(vector<int>& arr) {
        if(arr.empty()) return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
        int n = arr.size();
        for(int i=1;i<n;i++){
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        
        return head;
    }

    vector<int> traverse(ListNode* head) {
        vector<int> res;
        ListNode* curr = head;
        while(curr!=nullptr){
            res.push_back(curr->val);
            curr = curr->next;
        }
        
        return res;
    }
};
