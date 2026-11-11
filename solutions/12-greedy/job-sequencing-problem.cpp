#include <bits/stdc++.h>
using namespace std;

#define pb push_back

struct Job {
    int id;
    int dead;
    int profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

class Solution {
public:
    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, cmp);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, arr[i].dead);
        }

        vector<bool> vis(mx + 1, false);
        int ans = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) { // find latest available slot
                if (vis[j] == false) {
                    vis[j] = true;
                    ans += arr[i].profit;
                    cnt++;
                    break;
                }
            }
        }
        return {cnt, ans};
    }
};
