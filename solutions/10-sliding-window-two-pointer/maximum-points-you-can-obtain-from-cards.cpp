#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        int temp=0;
        for(int x:arr)temp+=x; // total sum of all cards
        int tot=temp;
        int len=n-k;

        if(len==0)return tot; // k==n, take all cards

        temp=0;
        for(int i=0;i<len;i++)temp+=arr[i];
        int mn=temp;

        for(int i=len;i<n;i++){
            temp+=arr[i]-arr[i-len];
            mn=min(mn,temp);
        }
        return tot-mn;
    }
};
