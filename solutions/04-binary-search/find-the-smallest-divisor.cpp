#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int>& arr, int x, int t) {
        long long sum=0;
        for(int num:arr){
            sum+=(num+x-1)/x;
        }
        return sum<=t;
    }

    int smallestDivisor(vector<int>& arr, int t) {
        int n=arr.size();
        int mx=0;
        for(int num:arr){
            if(num>mx) mx=num;
        }

        int l=1,r=mx;
        int ans=mx;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(arr,mid,t)){
                ans=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return ans;
    }
};
