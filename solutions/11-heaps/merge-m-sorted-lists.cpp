#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mergeKSortedLists(vector<vector<int>>& lists) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; // min-heap {val, {list_idx, element_idx}}

        int m=lists.size();
        for(int i=0;i<m;i++){
            if(!lists[i].empty()){
                pq.push({lists[i][0],{i,0}});
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            pair<int,pair<int,int>> curr=pq.top();
            pq.pop();

            int val=curr.first;
            int list_idx=curr.second.first;
            int elem_idx=curr.second.second;

            ans.push_back(val);

            if(elem_idx+1<lists[list_idx].size()){
                pq.push({lists[list_idx][elem_idx+1],{list_idx,elem_idx+1}});
            }
        }

        return ans;
        
    }
};
