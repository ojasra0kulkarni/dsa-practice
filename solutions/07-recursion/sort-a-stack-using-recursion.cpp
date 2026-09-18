#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

void insertSorted(stack<int>& s, int x) {
    if (s.empty() || x >= s.top()) {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insertSorted(s, x);
    s.push(temp); // put back previous elements
}

void sortStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int x = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s, x);
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);
    sortStack(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
