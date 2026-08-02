#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int ans = 0;
        for(int x : arr) {
            ans ^= x;
        }
        return ans;
    }
};
