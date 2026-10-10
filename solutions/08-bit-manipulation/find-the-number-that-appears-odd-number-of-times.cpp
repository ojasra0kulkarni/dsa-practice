#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution {
public:
    int findOddOccuring(vector<int> &arr) {
        int ans=0;
        for(int x:arr){
            ans^=x;
        }
        return ans;
    }
};
