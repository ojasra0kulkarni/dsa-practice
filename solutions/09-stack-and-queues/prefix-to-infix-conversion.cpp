#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOp(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    string prefixToInfix(string s) {
        stack<string> st;
        int n = s.length();

        for(int i=n-1;i>=0;i--) {
            if(isOp(s[i])) {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string res = "(" + op1 + s[i] + op2 + ")";
                st.push(res);
            } else {
                st.push(string(1, s[i]));
            }
        }
        return st.top();
    }
};
