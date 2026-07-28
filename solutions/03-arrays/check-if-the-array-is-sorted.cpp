#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    bool isSorted(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i-1]) return false; // current less than prev
        }
        return true;
    }
};
