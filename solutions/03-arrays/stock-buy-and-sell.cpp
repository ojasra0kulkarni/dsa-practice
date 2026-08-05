#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0];
        int mx = 0;

        for (int i = 1; i < n; i++) {
            mx = max(mx, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return mx;
    }
};

int main() {
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << Solution().maxProfit(a) << endl;
    return 0;
}
