#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;

class Solution {
public:
    string postfixToPrefix(string s) {
        stack<string> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
                string tmp;
                tmp += ch;
                st.push(tmp);
            } else {
                string op1 = st.top(); st.pop(); // right operand
                string op2 = st.top(); st.pop(); // left operand
                string res = ch + op2 + op1; // operator + left + right
                st.push(res);
            }
        }
        return st.top();
    }
};
