#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2; // mid overflow
            if (arr[mid] == x) return mid;
            else if (arr[mid] < x) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};
