#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(arr[i].begin(),arr[i].end());
        }
    }
};
