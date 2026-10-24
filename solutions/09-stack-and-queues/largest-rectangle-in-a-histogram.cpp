#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // calculate previous smaller element indices
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // clear stack
        while(!st.empty()) st.pop();

        // calculate next smaller element indices
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, (long long)arr[i] * (right[i] - left[i] - 1));
        }

        return mx;
    }
};
