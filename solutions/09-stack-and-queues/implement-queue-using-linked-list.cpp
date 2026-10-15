#include <bits/stdc++.h>
using namespace std;

#define pb push_back

struct Node {
    int dt;
    Node *nx;
    Node(int d) {
        dt = d;
        nx = nullptr;
    }
};

class Queue {
    Node *hd;
    Node *tl;
    int cnt;

public:
    Queue() {
        hd = nullptr;
        tl = nullptr;
        cnt = 0;
    }

    void push(int x) {
        Node *tmp = new Node(x);
        if(hd==nullptr) {
            hd = tmp;
            tl = tmp;
        } else {
            tl->nx = tmp;
            tl = tmp;
        }
        cnt++;
    }

    int pop() {
        if(hd==nullptr) return -1;
        int res = hd->dt;
        Node *tmp = hd;
        hd = hd->nx;
        if(hd==nullptr) {
            tl = nullptr;
        }
        delete tmp;
        cnt--;
        return res;
    }

    int front() {
        if(hd==nullptr) return -1;
        return hd->dt;
    }

    int size() {
        return cnt;
    }

    bool isEmpty() {
        return hd==nullptr;
    }
};
