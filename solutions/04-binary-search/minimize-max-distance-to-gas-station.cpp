#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    bool check(vector<int>& arr, int k, double mid) {
        int cnt=0; 
        for(int i=1;i<arr.size();i++){
            double gap=arr[i]-arr[i-1];
            cnt+=(int)ceil(gap/mid)-1; // stations to add for this gap
        }
        return cnt<=k;
    }

    double minmaxGasDist(vector<int>& arr, int k) {
        double lo=0.0;
        double hi=0.0;
        double temp=0.0; // used for max gap
        for(int i=1;i<arr.size();i++){
            temp=max(temp,(double)(arr[i]-arr[i-1]));
        }
        hi=temp;

        double ans=hi;

        for(int i=0;i<100;i++){ // fixed iterations for floating point precision
            double mid=lo+(hi-lo)/2.0;
            if(check(arr,k,mid)){
                ans=mid;
                hi=mid;
            }else{
                lo=mid;
            }
        }
        temp=arr.size(); // unrelated use of temp
        return ans;
    }
};
