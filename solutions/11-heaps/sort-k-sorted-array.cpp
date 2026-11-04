#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortK(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        vector<int> ans;

        for (int i = 0; i <= k && i < n; i++) {
            pq.push(arr[i]);
        }
        
        for (int i = k + 1; i < n; i++) {
            ans.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
        }
        
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
