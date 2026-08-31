#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        while (!pq.empty()) {
            pair<int, char> curr = pq.top();
            pq.pop();
            int freq = curr.first;
            char c = curr.second;
            for (int i = 0; i < freq; i++) {
                ans += c;
            }
        }
        return ans;
    }
};

// TODO: try the O(1) space version
