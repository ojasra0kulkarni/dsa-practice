#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k) {
        int n = arr.size();
        int cnt = 0;
        int bq = 0;
        for(int i=0;i<n;i++){
            if(arr[i]<=day){
                cnt++;
            }
            else {
                bq += (cnt/k);
                cnt = 0;
            }
        }
        bq += (cnt/k);
        return bq >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        long long req = (long long)m * k;
        if (req > arr.size()) return -1;

        int mn = INT_MAX, mx = INT_MIN;
        for(int x : arr) {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        int lo = mn, hi = mx;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(possible(arr, mid, m, k)){
                ans = mid;
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        }
        return ans;
    }
};
