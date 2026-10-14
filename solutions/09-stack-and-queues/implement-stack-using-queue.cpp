#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    queue<int> tmp;

    MyStack() {

    }

    void push(int x) {
        tmp.push(x);
        while (!q.empty()) {
            tmp.push(q.front());
            q.pop();
        }
        swap(q, tmp);
        
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
        
    }

    int top() {
        return q.front();
        
    }

    bool empty() {
        return q.empty();
        
    }
};
