#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double n, long long x) {
        double ans=1.0;
        long long tmp=x;

        if(tmp<0){
            n=1.0/n;
            tmp=-tmp;
        }

        // cout<<ans<<endl;

        while(tmp>0){
            if(tmp%2==1){ // if current bit is set
                ans=ans*n;
            }
            n=n*n;
            tmp=tmp/2;
        }
        return ans;
    }
};
