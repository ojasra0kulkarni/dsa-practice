#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    void solve(int r,int c,vector<vector<int>> &m,int n,vector<string> &ans,string path,vector<vector<int>> &vis,int dr[],int dc[],string ds) {
        if(r==n-1 && c==n-1) {
            ans.pb(path);
            return;
        }

        for(int i=0;i<4;i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && m[nr][nc]==1 && !vis[nr][nc]) {
                vis[nr][nc]=1;
                solve(nr,nc,m,n,ans,path+ds[i],vis,dr,dc,ds);
                vis[nr][nc]=0; // backtrack
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));

        // D L R U for lexicographical order
        int dr[]={1,0,0,-1};
        int dc[]={0,-1,1,0};
        string ds="DLRU";

        if(m[0][0]==1) {
            vis[0][0]=1;
            solve(0,0,m,n,ans,"",vis,dr,dc,ds);
        }
        return ans;
    }
};
