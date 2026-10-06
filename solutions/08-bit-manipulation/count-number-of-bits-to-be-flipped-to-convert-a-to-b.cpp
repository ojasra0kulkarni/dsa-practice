#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution {
public:
    int cntBitsFlip(int a, int b) {
        int x = a ^ b;
        int cnt = 0;
        while (x > 0) {
            x &= (x - 1); // clears the least significant set bit
            cnt++;
        }
        return cnt;
    }
};
