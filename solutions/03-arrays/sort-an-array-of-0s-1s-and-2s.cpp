#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int lo = 0;
        int hi = n - 1;
        int mid = 0;
        while (mid <= hi) {
            if (arr[mid] == 0) {
                swap(arr[lo], arr[mid]);
                lo++;
                mid++;
            } else if (arr[mid] == 1) {
                mid++;
            } else { // arr[mid] == 2
                swap(arr[mid], arr[hi]); // don't increment mid, new element needs check
                hi--;
            }
        }

    }
};
