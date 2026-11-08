#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCoins(int V) {
        vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int ans = 0;
        int n = coins.size();
        for(int i=0;i<n;i++){
            while(V >= coins[i]){
                V -= coins[i];
                ans++;
            }
        }
        return ans;
    }
};
