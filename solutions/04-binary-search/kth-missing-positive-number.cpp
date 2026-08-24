#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int l = 1, r = 3005; 
        int ans = r; 
        
        while (l <= r) {
            int mid = l + (r - l) / 2; // mid overflow
            
            int cnt = upper_bound(v.begin(), v.end(), mid) - v.begin(); // numbers in v <= mid
            
            int missing = mid - cnt;
            
            if (missing >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = {2,3,4,7,11};
    cout << s.findKthPositive(a, 5) << endl;
    return 0;
}
