#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int lowerBound(vector<int> arr, int n, int x) {
    int l=0, r=n-1;
    int ans=n;
    while(l<=r) {
        int mid=l+(r-l)/2; // mid overflow
        if(arr[mid]>=x) {
            ans=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    return ans;

}
