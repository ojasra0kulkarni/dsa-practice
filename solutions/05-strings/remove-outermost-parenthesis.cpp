#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int cnt=0;
        for(char c:s){
            if(c=='('){
                if(cnt>0) ans+=c; // if not outermost, append
                cnt++;
            }
            else{ // c == ')'
                cnt--;
                if(cnt>0) ans+=c;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    cout<<sol.removeOuterParentheses("(()())(())")<<endl;
    return 0;
}
