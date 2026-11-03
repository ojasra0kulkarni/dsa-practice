#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void maxHeapify(vector<int> &arr,int n,int i) {
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;

        if(l<n&&arr[l]>arr[largest]){
            largest=l;
        }

        if(r<n&&arr[r]>arr[largest]){
            largest=r;
        }

        if(largest!=i){
            swap(arr[i],arr[largest]);
            maxHeapify(arr,n,largest);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr) {
        int n=arr.size();
        for(int i=n/2-1;i>=0;i--){
            maxHeapify(arr,n,i);
        }

    }
};
