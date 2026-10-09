#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    void swapNumbers(int &a, int &b) {
        a = a ^ b;
        b = a ^ b; // b becomes original a
        a = a ^ b;
    }
};
