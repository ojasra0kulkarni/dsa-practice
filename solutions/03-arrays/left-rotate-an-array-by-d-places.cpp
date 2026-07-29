#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    void rotateArr(vector<int> &arr, int d) {
        int n = arr.size();
        if (n == 0) return;
        d %= n;
        if (d == 0) return;

        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};
