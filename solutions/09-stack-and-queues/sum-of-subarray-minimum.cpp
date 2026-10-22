#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n); 
        vector<int> nse(n); 
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        ll ans = 0;
        ll MOD = 1e9 + 7;

        for(int i=0;i<n;i++){
            ll l = i - pse[i];
            ll r = nse[i] - i;
            ans = (ans + (ll)arr[i] * l % MOD * r % MOD) % MOD;
        }

        return (int)ans;
    }
};
