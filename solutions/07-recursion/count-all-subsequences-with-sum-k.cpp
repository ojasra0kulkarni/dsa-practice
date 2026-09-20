#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int sum, int k, vector<int>& v, int n) {
        if(idx == n){ // base case
            if(sum == k) return 1;
            return 0;
        }

        // take it
        sum += v[idx];
        int take = solve(idx + 1, sum, k, v, n);
        sum -= v[idx]; // backtrack

        // not take it
        int ntake = solve(idx + 1, sum, k, v, n);

        return take + ntake;
    }

    int sub(vector<int>& arr, int k) {
        int n = arr.size();
        return solve(0, 0, k, arr, n);
    }
};
// ^ submitted, accepted
