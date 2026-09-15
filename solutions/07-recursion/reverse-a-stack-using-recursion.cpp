#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution {
public:
    void insertAtBottom(stack<int>& st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int el=st.top();
        st.pop();
        insertAtBottom(st,x);
        st.push(el);
    }

    void reverseStack(stack<int>& st){
        if(st.empty()) return;

        int el=st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st,el);
    }
};
