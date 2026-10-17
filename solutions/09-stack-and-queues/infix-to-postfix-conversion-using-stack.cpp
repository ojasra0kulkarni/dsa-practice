#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0; // for parentheses or other non-operators
    }

public:
    string infixToPostfix(string s) {
        string res = "";
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
                res += ch;
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // Pop '('
            } else { // Operator
                while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                    res += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
