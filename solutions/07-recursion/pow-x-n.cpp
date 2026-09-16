#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long N=n;
        
        if(N<0){
            N=-N;
            x=1/x;
        }
        
        while(N>0){
            if(N%2==1) ans=ans*x;
            x=x*x;
            N=N/2;
            // cout<<ans<<endl;
        }
        
        return ans;
    }
};
