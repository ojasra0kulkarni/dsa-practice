#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int mx=0;
        int curr=0;
        for(char ch:s){
            if(ch=='('){
                curr++;
                mx=max(mx,curr);
            } else if(ch==')'){
                curr--;
            }
        }
        return mx;
    }
};
