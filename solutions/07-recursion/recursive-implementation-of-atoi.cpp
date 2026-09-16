#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    ll rec(const string& s, int i, ll curr, int sign) {
        if(i==s.size()||!isdigit(s[i])) {
            return (sign==1)?min((ll)INT_MAX,curr):max((ll)INT_MIN,-curr);
        }

        int d=s[i]-'0';

        if(curr>INT_MAX/10||(curr==INT_MAX/10&&((sign==1&&d>7)||(sign==-1&&d>8)))) {
            return (sign==1)?INT_MAX:INT_MIN;
        }

        curr=curr*10+d;
        return rec(s,i+1,curr,sign);
    }

    int myAtoi(string s) {
        int n=s.size();
        int i=0;

        while(i<n&&s[i]==' ') i++;

        int sign=1;
        if(i<n&&(s[i]=='-'||s[i]=='+')) {
            if(s[i]=='-') sign=-1;
            i++;
        }

        ll res=rec(s,i,0,sign);
        return (int)res;
    }
};
