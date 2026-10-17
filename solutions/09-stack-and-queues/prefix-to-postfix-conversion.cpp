#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    string preToPost(string s) {
        stack<string> st;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) { // process from right to left
            if (isOperator(s[i])) {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string temp = op1 + op2 + s[i];
                st.push(temp);
            } else {
                string temp = "";
                temp += s[i];
                st.push(temp);
            }
        }
        return st.top();
    }
};
