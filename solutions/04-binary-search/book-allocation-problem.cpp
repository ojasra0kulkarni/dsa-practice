#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPoss(vector<int> &arr, int n, int m, int x) { // x is the max pages limit
        int cnt=1;
        long long sm=0;
        for(int i=0;i<n;i++){
            if(arr[i]>x) return false;
            if(sm+arr[i]<=x){
                sm+=arr[i];
            }else{
                cnt++;
                sm=arr[i];
            }
        }
        return cnt<=m;
    }

    int findPages(vector<int>& arr, int n, int m) {
        if(m>n) return -1;

        int l=0, r=0;
        for(int pages : arr){
            l=max(l, pages);
            r+=pages;
        }

        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2; // mid overflow
            if(isPoss(arr, n, m, mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
