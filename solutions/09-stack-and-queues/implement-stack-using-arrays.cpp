#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class MyStack {
public:
    int arr[1000];
    int sz;

    MyStack() {
        sz = -1;
    }
    
    void push(int x) {
        sz++;
        arr[sz] = x;
    }
    
    int pop() {
        if (sz == -1) return -1; // handle underflow, or throw error
        int val = arr[sz];
        sz--;
        return val;
    }
    
    int top() {
        if (sz == -1) return -1; // handle empty stack
        return arr[sz];
    }
    
    int size() {
        return sz + 1;
    }
    
    bool isEmpty() {
        return sz == -1;
    }
};
