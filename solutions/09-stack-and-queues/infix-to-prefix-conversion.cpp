#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prec(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    bool isRightAssociative(char c) {
        return c == '^';
    }

    string infixToPostfix(string s) {
        string res = "";
        stack<char> st;
        for (char c : s) {
            if (isalnum(c)) {
                res += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop(); // pop (
                }
            } else { // Operator
                while (!st.empty() && st.top() != '(') {
                    if (prec(c) > prec(st.top())) {
                        break;
                    }
                    if (prec(c) == prec(st.top()) && isRightAssociative(c)) {
                        break;
                    }
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }

    string infixToPrefix(string s) {
        reverse(s.begin(), s.end());

        string temp = "";
        for (char c : s) {
            if (c == '(') {
                temp += ')';
            } else if (c == ')') {
                temp += '(';
            } else {
                temp += c;
            }
        }
        
        temp = infixToPostfix(temp);
        // cout<<temp<<endl;

        reverse(temp.begin(), temp.end());
        return temp;
    }
};
