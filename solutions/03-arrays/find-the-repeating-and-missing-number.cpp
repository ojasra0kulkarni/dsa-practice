#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Solution {
public:
    vector<int> findTwoElement(vector<int> &arr, int n) {
        ll s = 0; 
        ll sqs = 0; 

        for(int x:arr) {
            s += x;
            sqs += (ll)x * x;
        }

        ll expS = (ll)n * (n + 1) / 2;
        ll expSqS = (ll)n * (n + 1) * (2 * n + 1) / 6;

        ll diff1 = s - expS; // x - y
        ll diff2 = sqs - expSqS; // x^2 - y^2

        ll sumXY = diff2 / diff1; // (x+y) from (x^2-y^2)/(x-y)

        ll rep = (diff1 + sumXY) / 2;
        ll mis = (sumXY - diff1) / 2;

        return {(int)rep, (int)mis};
    }
};
