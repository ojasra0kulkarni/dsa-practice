#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int l=0; // start of current word
        for(int r=0; r<n; r++) {
            if(s[r]==' ') {
                reverse(s.begin()+l, s.begin()+r);
                l=r+1; // start of next word
            }
        }
        // reverse last word
        reverse(s.begin()+l, s.end());
        return s;
    }
};

int main() {
    Solution sol;
    string s="Let's take LeetCode contest";
    cout<<sol.reverseWords(s)<<endl;
    return 0;
}
