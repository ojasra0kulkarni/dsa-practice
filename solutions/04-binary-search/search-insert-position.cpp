#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0, r=n-1;
        int ans=n; // potential insert at end
        while(l<=r){
            int mid=l+(r-l)/2; // avoid overflow
            if(arr[mid]>=target){
                ans=mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return ans;
        
    }
}
