#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long power(long long b, long long e) {
        long long res = 1;
        long long mod = 1e9 + 7;
        b %= mod;
        while(e > 0){
            if(e % 2 == 1) res = (res * b) % mod;
            b = (b * b) % mod;
            e /= 2;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        long long e_cnt = (n + 1) / 2;
        long long o_cnt = n / 2;      
        
        long long temp = power(5, e_cnt);
        long long ans = (temp * power(4, o_cnt)) % mod;
        
        return (int)ans;
    }
};
