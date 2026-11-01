#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if (m == 0) return "";

        int ans_st = 0;
        int min_len = INT_MAX;
        
        int i = 0;
        int j = 0;
        
        while (i < n) {
            if (s[i] == t[j]) {
                j++;
            }
            
            if (j == m) {
                int end = i;
                int curr_i = i;
                int curr_j = m - 1;
                
                while (curr_j >= 0) {
                    if (s[curr_i] == t[curr_j]) {
                        curr_j--;
                    }
                    curr_i--;
                }
                int start = curr_i + 1;
                
                if (end - start + 1 < min_len) {
                    min_len = end - start + 1;
                    ans_st = start;
                }
                
                i = start; 
                j = 0;
            }
            i++;
        }
        
        if (min_len == INT_MAX) {
            return "";
        }
        return s.substr(ans_st, min_len);
    }
};
