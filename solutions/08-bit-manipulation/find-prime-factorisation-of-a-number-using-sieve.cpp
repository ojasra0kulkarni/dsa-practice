#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MX = 1000001;
    static int spf[MX]; // smallest prime factor
    static bool vis; // sieve run flag

    static void precompute(){
        if(vis) return;
        for(int i=0;i<MX;i++) spf[i]=i;
        for(int i=2;i*i<MX;i++){
            if(spf[i]==i){
                for(int j=i*i;j<MX;j+=i){
                    if(spf[j]==j) spf[j]=i;
                }
            }
        }
        vis=true;
    }

    vector<int> primeFactors(int n){
        precompute();
        vector<int> ans;
        while(n>1){
            ans.push_back(spf[n]);
            n/=spf[n];
        }
        return ans;
    }
};

int Solution::spf[Solution::MX];
bool Solution::vis = false;
