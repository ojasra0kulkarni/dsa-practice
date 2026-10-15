#include <bits/stdc++.h>
using namespace std;

#define pb push_back

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* head;
    int cnt;

public:
    Stack() {
        head = nullptr;
        cnt = 0;
    }

    void push(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
        cnt++;
    }

    void pop() {
        if (head == nullptr) { // empty stack
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
        cnt--;
    }

    int top() {
        if (head == nullptr) { // empty stack
            return -1; // common for empty
        }
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        return cnt;
    }
};
