#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        int i=0;
        while(i<n){
            while(i<n&&s[i]==' ') i++; // skip leading spaces
            if(i==n) break;
            int j=i;
            while(j<n&&s[j]!=' ') j++; // find end of word
            string word=s.substr(i,j-i);
            if(ans.empty()){
                ans=word;
            } else {
                ans=word+" "+ans; // prepend word to result
            }
            i=j;
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    string test="  hello world  ";
    cout<<sol.reverseWords(test)<<endl;
    
    return 0;
}
