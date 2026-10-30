#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long cntAtMost(vector<int>& v, int s) {
        if(s < 0) return 0;
        long long ans=0;
        int l=0,sum=0;
        for(int r=0;r<v.size();r++){
            sum+=v[r];
            while(sum > s){ // shrink window if sum exceeds target
                sum-=v[l];
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return cntAtMost(nums, goal) - cntAtMost(nums, goal - 1);
    }
};

int main() {
    Solution sol;
    vector<int> a={1,0,1,0,1};
    int g=2;
    cout<<sol.numSubarraysWithSum(a,g)<<endl;
    return 0;
}
