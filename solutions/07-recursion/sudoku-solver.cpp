#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& b, int r, int c, char d) {
        for (int i = 0; i < 9; i++) {
            if (b[r][i] == d) return false;
            if (b[i][c] == d) return false;
            if (b[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == d) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& b) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (b[r][c] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(b, r, c, d)) {
                            b[r][c] = d;
                            if (solve(b)) {
                                return true;
                            }
                            b[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& b) {
        solve(b);
    }
};
