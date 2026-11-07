#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int> &a, vector<int> &b, int n) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        priority_queue<pair<int,pair<int,int>>> pq; // max-heap for sums
        set<pair<int,int>> vis; // track visited pairs to avoid dups

        pq.push({a[n-1]+b[n-1],{n-1,n-1}});
        vis.insert({n-1,n-1});

        vector<int> ans;
        for(int cnt=0;cnt<n;cnt++) {
            auto top = pq.top();
            pq.pop();
            
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back(sum);
            
            if(i-1>=0 && vis.find({i-1,j})==vis.end()) {
                pq.push({a[i-1]+b[j],{i-1,j}});
                vis.insert({i-1,j});
            }
            
            if(j-1>=0 && vis.find({i,j-1})==vis.end()) {
                pq.push({a[i]+b[j-1],{i,j-1}});
                vis.insert({i,j-1});
            }
        }
        return ans;
    }
};
