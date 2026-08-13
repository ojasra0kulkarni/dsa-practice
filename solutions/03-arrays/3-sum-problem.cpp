#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end()); // sort to use two pointer

        for(int i=0; i<n; i++) {
            if(i>0 && arr[i]==arr[i-1]) continue; // skip duplicate i

            int l=i+1, r=n-1;
            while(l<r) {
                int s = arr[i]+arr[l]+arr[r];
                if(s==0) {
                    ans.push_back({arr[i], arr[l], arr[r]});
                    l++; r--;
                    while(l<r && arr[l]==arr[l-1]) l++;
                    while(l<r && arr[r]==arr[r+1]) r--;
                }
                else if(s<0) l++;
                else r--;
            }
        }
        return ans;
    }
};
