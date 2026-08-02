#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        int mx = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==1) cnt++;
            else cnt=0;
            mx = max(mx,cnt); // always update max
        }

        return mx;
    }

};
