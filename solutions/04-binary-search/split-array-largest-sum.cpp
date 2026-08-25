#include <bits/stdc++.h>
using namespace std;

bool check(long long mid, vector<int>& arr, int k){
    long long curr = 0;
    int cnt = 1;
    for(int x : arr){
        if(x > mid) return false;
        if(curr + x > mid){
            cnt++;
            curr = x;
        } else {
            curr += x;
        }
    }
    return cnt <= k;
}

class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        long long l = 0, r = 0;
        for(int x : arr){
            if(x > l) l = x;
            r += x;
        }

        long long ans = r;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if(check(mid, arr, k)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return (int)ans;
    }
};

int main() {
    Solution s;
    vector<int> a = {7,2,5,10,8}; int k = 2;
    cout << s.splitArray(a, k) << endl;
    return 0;
}
