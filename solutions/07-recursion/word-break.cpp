#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i,string &str,unordered_set<string> &st,vector<int> &dp){
        int n=str.length();
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];

        for(int j=i;j<n;j++){
            string sub=str.substr(i,j-i+1);
            if(st.count(sub)){
                if(solve(j+1,str,st,dp)){
                    return dp[i]=true; // update memo and return true
                }
            }
        }
        return dp[i]=false;
    }

    bool wordBreak(string s,vector<string>& wd){
        unordered_set<string> st;
        for(string &x:wd){
            st.insert(x);
        }

        int n=s.length();
        vector<int> dp(n+1,-1);

        return solve(0,s,st,dp);
    }
};
