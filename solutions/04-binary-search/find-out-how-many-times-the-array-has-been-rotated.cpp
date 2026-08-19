#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n=arr.size();
        int lo=0,hi=n-1;
        int ans=arr[0];
        int idx=0;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(arr[lo]<=arr[mid]){ 
                if(arr[lo]<ans){
                    ans=arr[lo];
                    idx=lo;
                }
                lo=mid+1;
            } else { 
                if(arr[mid]<ans){
                    ans=arr[mid];
                    idx=mid;
                }
                hi=mid-1;
            }
        }
        return idx;
    }
};
