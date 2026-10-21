#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countNGEs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nxt_idx(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nxt_idx[i] = st.top();
            }
            st.push(i);
        }

        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            if (nxt_idx[i] == -1) {
                ans[i] = 0;
            } else {
                ans[i] = 1 + ans[nxt_idx[i]];
            }
        }
        
        return ans;
    }
};
