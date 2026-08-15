#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long merge(vector<int> &arr, int lo, int mid, int hi) {
        vector<int> tmp;
        long long inv = 0;
        int l = lo;
        int r = mid + 1;

        while (l <= mid && r <= hi) {
            if (arr[l] <= arr[r]) {
                tmp.push_back(arr[l]);
                l++;
            } else { 
                tmp.push_back(arr[r]);
                inv += (mid - l + 1); // count elements still in left array
                r++;
            }
        }

        while (l <= mid) {
            tmp.push_back(arr[l]);
            l++;
        }
        while (r <= hi) {
            tmp.push_back(arr[r]);
            r++;
        }

        for (int i = lo; i <= hi; i++) {
            arr[i] = tmp[i - lo];
        }
        return inv;
    }

    long long mergeSort(vector<int> &arr, int lo, int hi) {
        long long inv = 0;
        if (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            inv += mergeSort(arr, lo, mid);
            inv += mergeSort(arr, mid + 1, hi);
            inv += merge(arr, lo, mid, hi);
        }
        return inv;
    }

public:
    long long numberOfInversions(vector<int> &a, int n) {
        return mergeSort(a, 0, n - 1);
    }
};
