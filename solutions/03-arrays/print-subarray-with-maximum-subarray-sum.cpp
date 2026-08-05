#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubarray(vector<int>&arr) {
        int n=arr.size();
        long long mx=-1e18; 
        long long sum=0;
        int l=0, r=0;
        int tmp=0; // start of current subarray

        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mx){
                mx=sum;
                l=tmp;
                r=i;
            }
            if(sum<0){ // reset sum if negative
                sum=0;
                tmp=i+1;
            }
        }
        
        vector<int> res;
        for(int i=l;i<=r;i++){
            res.push_back(arr[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> ans = s.maxSubarray(a);
    for(int x:ans) cout << x << " ";
    cout << endl;
    return 0;
}

// TODO: try the O(1) space version
