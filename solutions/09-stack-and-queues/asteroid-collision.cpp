#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int> st;
        for (int x : v) {
            if (x > 0) {
                st.push(x);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < -x) {
                    st.pop(); // smaller positive explodes
                }
                
                if (st.empty() || st.top() < 0) {
                    st.push(x);
                } else if (st.top() == -x) {
                    st.pop(); // both explode
                }
                // else current x explodes
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = {10, 2, -5};
    vector<int> res = s.asteroidCollision(a);
    for (int x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}
