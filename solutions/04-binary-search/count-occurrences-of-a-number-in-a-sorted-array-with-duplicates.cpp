#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int firstOcc(vector<int>& arr, int x, int n) {
        int l=0, r=n-1, ans=-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(arr[mid]==x) {
                ans = mid;
                r = mid-1; // search left for first occurrence
            }
            else if(arr[mid]<x) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return ans;
    }

    int lastOcc(vector<int>& arr, int x, int n) {
        int l=0, r=n-1, ans=-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(arr[mid]==x) {
                ans = mid;
                l = mid+1; // search right for last occurrence
            }
            else if(arr[mid]<x) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return ans;
    }

    int count(vector<int>& arr, int n, int x) {
        int first = firstOcc(arr, x, n);
        if(first == -1) return 0;
        int last = lastOcc(arr, x, n);
        return last - first + 1;
    }
};
