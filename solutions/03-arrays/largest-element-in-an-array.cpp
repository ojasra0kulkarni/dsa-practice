#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestElement(vector<int> &arr) {
        int n = arr.size();
        int mx = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > mx) {
                mx = arr[i];
            }
        }
        return mx;
    }
};
