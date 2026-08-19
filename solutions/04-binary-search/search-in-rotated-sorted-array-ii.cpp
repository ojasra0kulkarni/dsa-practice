#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                return true;
            }

            if (arr[l] == arr[mid]) {
                l++;
                continue;
            }
            if (arr[r] == arr[mid]) {
                r--;
                continue;
            }

            if (arr[l] < arr[mid]) {
                if (arr[l] <= target && target < arr[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            else {
                if (arr[mid] < target && target <= arr[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};
