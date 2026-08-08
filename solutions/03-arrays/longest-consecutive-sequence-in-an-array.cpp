#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.empty())return 0;

        unordered_set<int> st;
        for(int x:arr)st.insert(x);

        int mx=0;
        for(int x:st) {
            if(st.find(x-1)==st.end()) { // check if x is sequence start
                int curr=x;
                int cnt=1;
                while(st.find(curr+1)!=st.end()) {
                    curr++;
                    cnt++;
                }
                mx=max(mx,cnt);
            }
        }
        return mx;
    }
};
