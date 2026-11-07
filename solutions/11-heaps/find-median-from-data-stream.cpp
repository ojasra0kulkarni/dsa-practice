#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> pq1; // max-heap for smaller half
    priority_queue<int, vector<int>, greater<int>> pq2; // min-heap for larger half

    MedianFinder() {

    }
    
    void addNum(int x) {
        if(pq1.empty() || x <= pq1.top()) pq1.push(x);
        else pq2.push(x);

        if(pq1.size() > pq2.size() + 1) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        if(pq2.size() > pq1.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        if(pq1.size() == pq2.size()) {
            return ((double)pq1.top() + pq2.top()) / 2.0;
        } else {
            return (double)pq1.top();
        }
    }
};
