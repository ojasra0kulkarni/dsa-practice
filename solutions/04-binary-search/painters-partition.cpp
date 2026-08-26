#include <bits/stdc++.h>
using namespace std;

bool can(long long m,int k,vector<int>& arr){
    long long cs=0;
    int c=1;
    for(int x:arr){
        if(x>m) return false;
        if(cs+x<=m) cs+=x;
        else{
            c++;
            cs=x;
        }
    }
    return c<=k;
}

class Solution {
public:
    int findLargestMinimisedMaxSum(vector<int>& arr,int k) {
        long long l=0;
        long long r=0;
        for(int x:arr){
            l=max(l,(long long)x);
            r+=x;
        }

        long long ans=r;

        while(l<=r){
            long long m=l+(r-l)/2;
            if(can(m,k,arr)){
                ans=m;
                r=m-1;
            } else l=m+1;
        }
        return (int)ans;
    }
};

int main() {
    Solution s;
    vector<int> arr={10,20,30,40};
    int k=2;
    cout<<s.findLargestMinimisedMaxSum(arr,k)<<endl;
    return 0;
}
