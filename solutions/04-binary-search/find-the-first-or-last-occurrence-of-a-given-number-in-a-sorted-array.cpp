#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstOcc(vector<int>&arr,int x) {
        int n=arr.size();
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r) {
            int mid=l+(r-l)/2; // mid overflow
            if(arr[mid]==x) {
                ans=mid;
                r=mid-1;
            } else if(arr[mid]<x) {
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        return ans;
    }

    int lastOcc(vector<int>&arr,int x) {
        int n=arr.size();
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r) {
            int mid=l+(r-l)/2; // mid overflow
            if(arr[mid]==x) {
                ans=mid;
                l=mid+1;
            } else if(arr[mid]<x) {
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr={1,2,3,3,3,4,5,5};
    int x=3;
    cout<<s.firstOcc(arr,x)<<
