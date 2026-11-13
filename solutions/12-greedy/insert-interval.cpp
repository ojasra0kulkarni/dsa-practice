#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& curr) {
        vector<vector<int>> ans;
        int n = v.size();
        int st = curr[0];
        int en = curr[1];
        int i = 0;

        while (i < n && v[i][1] < st) {
            ans.push_back(v[i]);
            i++;
        }

        while (i < n && v[i][0] <= en) {
            st = min(st, v[i][0]);
            en = max(en, v[i][1]);
            i++;
        }
        ans.push_back({st, en});

        while (i < n) {
            ans.push_back(v[i]);
            i++;
        }

        return ans;
        
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{1,3},{6,9}};
    vector<int> curr = {2,5};
    vector<vector<int>> res = s.insert(v, curr);
    cout << res.size() << endl;

    return 0;
}
