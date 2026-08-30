#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')%2!=0){ // check if digit is odd
                return s.substr(0,i+1);
            }
        }
        return "";

    }
};
