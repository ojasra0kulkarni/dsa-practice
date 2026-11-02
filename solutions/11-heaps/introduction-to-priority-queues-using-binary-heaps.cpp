#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kLargest(vector<int>& arr, int k) {
        int n = arr.size();
        // min-heap to store k largest elements
        priority_queue<int, vector<int>, greater<int>> pq; 

        for (int x : arr) {
            pq.push(x);
            // if heap size exceeds k, remove smallest
            if (pq.size() > k) pq.pop(); 
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
