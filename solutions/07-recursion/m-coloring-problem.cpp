#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int c, vector<int>& colors, vector<vector<int>>& adj) {
    for (int x : adj[node]) {
        if (colors[x] == c) return false;
    }
    return true;
}

bool solve(int node, int n, int m, vector<int>& colors, vector<vector<int>>& adj) {
    if (node == n) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c, colors, adj)) {
            colors[node] = c;
            if (solve(node + 1, n, m, colors, adj)) return true;
            colors[node] = 0; // backtrack
        }
    }
    return false;
}

class Solution {
public:
    bool graphColoring(vector<vector<int>> &mat, int m) {
        int n = mat.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j]==1) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> colors(n, 0);
        return solve(0, n, m, colors, adj);
    }
};

int main() {
    vector<vector<int>> mat = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };
    int m = 3;
    Solution sol;
    cout<<sol.graphColoring(mat, m)<<endl;
    return 0;
}
