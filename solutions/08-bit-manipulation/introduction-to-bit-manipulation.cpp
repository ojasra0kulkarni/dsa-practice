#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // get i-th bit
    int getBit(int n, int i) {
        return (n >> i) & 1;
    }

    // set i-th bit to 1
    int setBit(int n, int i) {
        return n | (1 << i);
    }

    // clear i-th bit to 0
    int clearBit(int n, int i) {
        return n & (~(1 << i));
    }

    // toggle i-th bit
    int toggleBit(int n, int i) {
        return n ^ (1 << i);
    }
};
