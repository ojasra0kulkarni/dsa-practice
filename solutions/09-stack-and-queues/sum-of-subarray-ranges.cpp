#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subarrayRanges(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> ls(n), rs(n), lg(n), rg(n);
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ls[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop(); 

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            rs[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop(); 

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            lg[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop(); 

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            rg[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long smn = 0; // total sum of min contributions
        for(int i=0; i<n; i++) {
            smn += (long long)arr[i] * (i - ls[i]) * (rs[i] - i);
        }

        long long smx = 0; // total sum of max contributions
        for(int i=0; i<n; i++) {
            smx += (long long)arr[i] * (i - lg[i]) * (rg[i] - i);
        }

        return smx - smn;

    }
};
