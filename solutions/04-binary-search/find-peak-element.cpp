#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < arr[mid+1]) {
                l = mid + 1;
            }
            else {
                r = mid; // mid could be the peak
            }
        }
        return l;
    }

};
