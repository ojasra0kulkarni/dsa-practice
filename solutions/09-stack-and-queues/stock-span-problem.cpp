#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<pair<int, int>> st; // price, index

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first <= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = i + 1;
            } else {
                ans[i] = i - st.top().second;
            }
            st.push({arr[i], i});
            // cout<<ans[i]<<endl;
        }
        return ans;
    }
};
