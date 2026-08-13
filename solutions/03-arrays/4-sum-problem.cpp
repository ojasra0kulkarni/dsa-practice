#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());

        for(int i=0;i<n;i++){
            if(i > 0 && arr[i] == arr[i-1]) continue;

            for(int j=i+1;j<n;j++){
                if(j > i+1 && arr[j] == arr[j-1]) continue;

                long long rem = (long long)target - arr[i] - arr[j];
                int l = j+1;
                int r = n-1;

                while(l < r){
                    if(arr[l] + arr[r] == rem){
                        res.push_back({arr[i], arr[j], arr[l], arr[r]});
                        l++;
                        r--;
                        while(l < r && arr[l] == arr[l-1]) l++;
                        while(l < r && arr[r] == arr[r+1]) r--;
                    }
                    else if(arr[l] + arr[r] < rem) l++;
                    else r--;
                }
            }
        }
        // cout<<res.size()<<endl;
        return res;
    }
};
