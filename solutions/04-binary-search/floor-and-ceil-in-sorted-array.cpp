#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
    int f = -1;
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2; // mid overflow
        if (arr[mid] <= x) {
            f = arr[mid];
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    int c = -1;
    l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x) {
            c = arr[mid];
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return {f, c};
    
}
