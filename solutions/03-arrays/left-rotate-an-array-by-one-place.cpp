#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution {
public:
    void leftRotate(vector<int> &arr) {
        int n = arr.size();
        if (n <= 1) return; 
        int tmp = arr[0];
        for(int i=0;i<n-1;i++){
            arr[i] = arr[i+1];
        }
        arr[n-1] = tmp;
    }
};

// edge case: empty input handled above
