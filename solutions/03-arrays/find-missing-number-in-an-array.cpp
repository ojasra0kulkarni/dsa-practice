#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        long long temp = (long long)n * (n + 1) / 2; // calculate expected total sum
        for(int x : arr) {
            temp -= x;
        }
        return (int)temp;
    }
};
