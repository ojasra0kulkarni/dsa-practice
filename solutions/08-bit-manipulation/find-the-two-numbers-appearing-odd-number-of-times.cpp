#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    vector<int> twoOddNum(vector<int> &arr) {
        int s = 0;
        for(int x:arr) s^=x;

        int m = s & (-s); // this bit will be different for the two numbers

        int x = 0, y = 0;
        for(int n:arr){
            if((n&m)!=0) x^=n;
            else y^=n;
        }
        return {x,y};
    }
};
