#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int x) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==x) return mid;

            // left half is sorted
            if(arr[l]<=arr[mid]){
                if(arr[l]<=x && x<arr[mid]){ // target in left sorted part
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            // right half is sorted
            else{
                if(arr[mid]<x && x<=arr[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};
