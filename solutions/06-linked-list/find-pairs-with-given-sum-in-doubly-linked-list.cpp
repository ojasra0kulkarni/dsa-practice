#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

class Solution {
public:
    vector<pair<int, int>> findPairs(Node* head, int k) {
        vector<pair<int, int>> ans;
        if (!head || !head->next) {
            return ans;
        }

        Node* l = head;
        Node* r = head;
        while (r->next) {
            r = r->next;
        }

        while (l != r && r->next != l) {
            int sum = l->data + r->data;
            if (sum == k) {
                ans.push_back({l->data, r->data});
                l = l->next;
                r = r->prev;
            } else if (sum < k) {
                l = l->next;
            } else { 
                r = r->prev;
            }
        }
        return ans;
    }
};
