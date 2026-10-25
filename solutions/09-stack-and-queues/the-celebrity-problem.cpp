#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class Solution {
public:
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;
        for(int i=0;i<n;i++) s.push(i);

        while(s.size()>1){
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            if(M[a][b]==1) s.push(b);
            else s.push(a);
        }

        int c = s.top(); // potential celeb

        // verify c
        for(int i=0;i<n;i++){
            if(i!=c){
                // c must not know i, i must know c
                if(M[c][i]==1 || M[i][c]==0) return -1;
            }
        }
        return c;
    }
};
