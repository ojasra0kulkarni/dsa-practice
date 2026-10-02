#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int N, M;
    string S;
    vector<vector<char>> B;

    bool dfs(int i, int j, int k) {
        if(k == S.length()) return true; // full word found
        if(i < 0 || i >= N || j < 0 || j >= M || B[i][j] != S[k]) return false;

        char temp = B[i][j]; // save char for backtracking
        B[i][j] = '#'; // mark as visited

        bool found = dfs(i + 1, j, k + 1) ||
                     dfs(i - 1, j, k + 1) ||
                     dfs(i, j + 1, k + 1) ||
                     dfs(i, j - 1, k + 1);

        B[i][j] = temp; // backtrack, restore char
        return found;
    }

    bool exist(vector<vector<char>>& b, string s) {
        B = b;
        S = s;
        N = B.size();
        M = B[0].size();

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(B[i][j] == S[0]) { // possible start of word
                    if(dfs(i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
