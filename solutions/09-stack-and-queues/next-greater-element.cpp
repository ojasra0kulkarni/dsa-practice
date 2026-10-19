#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){ // pop smaller or equal elements
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            } else {
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};
