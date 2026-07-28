#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;

        int j = 1;
        for(int i=1;i<n;i++){
            if(arr[i]!=arr[j-1]){
                arr[j] = arr[i];
                j++;
            }
        }
        return j;

    }
};
