#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution {
public:
    bool search(vector<int>& arr, int x) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==x) return true;
        }
        return false;
    }
};
