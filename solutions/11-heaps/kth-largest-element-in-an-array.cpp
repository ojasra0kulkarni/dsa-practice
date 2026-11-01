#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min heap

        for (int x : arr) {
            pq.push(x);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // cout<<pq.top()<<endl;
        return pq.top();
    }
};
