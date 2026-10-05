#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setRightmostUnsetBit(int n) {
        if(n==INT_MAX || n==-1) return n; 
        int temp=(~n);
        int mask=(temp)&(n+1);
        return n|mask;
    }
};
