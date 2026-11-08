#include <bits/stdc++.h>
using namespace std;

struct Meet {
    int s, e, idx;
};

// custom comparator for sorting meetings
bool comp(Meet a, Meet b) {
    if (a.e != b.e) return a.e < b.e;
    return a.idx < b.idx; // tie-break with original index
}

class Solution {
public:
    int maxMeetings(int st[], int en[], int n) {
        vector<Meet> v(n);
        for (int i = 0; i < n; i++) {
            v[i].s = st[i];
            v[i].e = en[i];
            v[i].idx = i + 1;
        }

        sort(v.begin(), v.end(), comp);

        int cnt = 1;
        int last_e = v[0].e;

        for (int i = 1; i < n; i++) {
            if (v[i].s > last_e) {
                cnt++;
                last_e = v[i].e;
            }
        }
        return cnt;
    }
};

// TODO: try the O(1) space version
