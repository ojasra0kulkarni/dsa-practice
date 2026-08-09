#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr1, vector<int>& arr2, int n, int m) {
        int i = n - 1;
        int j = 0;

        while (i >= 0 && j < m) {
            if (arr1[i] > arr2[j]) {
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            } else {
                break; // elements are already in correct relative positions
            }
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
    }
};
