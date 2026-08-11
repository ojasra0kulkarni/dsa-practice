#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<long long, int> mp;
        long long sum = 0;
        int cnt = 0;
        mp[0] = 1; // for subarrays starting from index 0

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            long long rem = sum - k;
            if (mp.count(rem)) {
                cnt += mp[rem];
            }
            mp[sum]++;
            // cout<<cnt<<endl;
        }
        return cnt;
    }
};

int main() {
    vector<int> a = {1, 2, 3};
    Solution s;
    cout << s.subarraySum(a, 3) << endl;
    return 0;
}
