#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool isMinHeap(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n/2;i++){ // last non-leaf node is n/2 - 1
            int lc = 2*i+1;
            int rc = 2*i+2;

            if(lc<n && arr[i]>arr[lc]) return false;
            if(rc<n && arr[i]>arr[rc]) return false;
        }
        return true;
    }
};

// TODO: try the O(1) space version
