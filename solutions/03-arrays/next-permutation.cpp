#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                k = i;
                break;
            }
        }

        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int l = -1;
        for (int i = n - 1; i > k; i--) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        
        swap(nums[k], nums[l]);
        
        reverse(nums.begin() + k + 1, nums.end());
    }
};
