#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        int ans=INT_MAX;

        while(l<=r){
            int mid=l+(r-l)/2; // mid overflow

            if(arr[l]<=arr[mid]){ // left half is sorted
                ans=min(ans,arr[l]);
                l=mid+1;
            } else { // right half is sorted, min is arr[mid] or left
                ans=min(ans,arr[mid]);
                r=mid-1;
            }
        }
        return ans;
    }
};
// ^ submitted, accepted
