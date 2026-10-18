#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string postfixToInfix(string s) {
        stack<string> st;
        for(char c:s){
            if(isalnum(c)){
                string temp = "";
                temp += c;
                st.push(temp);
            }
            else{
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                string temp = "(" + op1 + c + op2 + ")";
                st.push(temp);
            }
        }
        return st.top();
    }
};
