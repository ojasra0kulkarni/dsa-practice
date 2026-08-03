#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, int k) {
    int temp=arr.size();
    int l=0,r=0;
    long long sum=0;
    int mx=0;
    
    while(r<temp){
        sum+=arr[r];
        while(sum>k){
            sum-=arr[l];
            l++;
        }
        if(sum==k){temp=r-l+1;mx=max(mx,temp);}
        r++;
    }
    return mx;
}

int main(){
    vector<int> a={1,2,3,1,1,1,4,2,3};
    int k_val=3;
    cout<<longestSubarrayWithSumK(a,k_val)<<endl;
    return 0;
}
