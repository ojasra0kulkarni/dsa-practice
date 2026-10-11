#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    int *a;
    int f, r;
    int n, cnt; // n: capacity, cnt: current size
public:
    MyQueue(int cap) {
        n = cap;
        a = new int[n];
        f = 0;
        r = -1; // r tracks the index of the last element
        cnt = 0;
    }

    void push(int x) {
        if (cnt == n) return;
        r = (r + 1) % n; // wrap around if at end
        a[r] = x;
        cnt++;
    }

    int pop() {
        if (cnt == 0) return -1; // problem specific: empty pop returns -1
        int res = a[f];
        f = (f + 1) % n;
        cnt--;
        return res;
    }

    int front() {
        if (cnt == 0) return -1;
        return a[f];
    }

    bool isEmpty() {
        return cnt == 0;
    }
};

int main() {
    MyQueue q(3);
    q.push(10);
    q.push(20);
    q.pop();
    cout << q.front() << endl;
    return 0;
}
