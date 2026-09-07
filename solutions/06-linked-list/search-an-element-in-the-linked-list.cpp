#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    bool search(Node* head, int k) {
        Node* curr = head;
        while(curr!=nullptr){
            if(curr->data==k) return true;
            curr = curr->next;
        }
        return false;
    }
};
