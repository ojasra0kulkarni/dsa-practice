#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondLargest(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return -1;

        int mx = INT_MIN;
        int smx = INT_MIN;

        for (int x : arr) {
            if (x > mx) {
                smx = mx;
                mx = x;
            } else if (x > smx && x != mx) {
                smx = x;
            }
        }
        
        return smx == INT_MIN ? -1 : smx;
    }
};
