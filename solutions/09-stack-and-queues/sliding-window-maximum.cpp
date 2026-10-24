#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq; // stores indices
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // remove elements out of window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // remove smaller elements from back
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // add to result once window is formed
            if (i >= k - 1) {
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};
