#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> sieve(int n) {
        vector<bool> vis(n + 1, true);
        vis[0] = vis[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (vis[p]) {
                for (int i = p * p; i <= n; i += p) {
                    vis[i] = false;
                }
            }
        }

        vector<int> primes;
        for (int p = 2; p <= n; p++) {
            if (vis[p]) {
                primes.push_back(p);
            }
        }
        return primes;
    }
};
