#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq; // min heap
    int k;

    KthLargest(int K_param, vector<int>& arr) {
        k=K_param;
        for(int x:arr){
            add(x);
        }
    }

    int add(int val) {
        if(pq.size()<k){
            pq.push(val);
        }
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        // cout<<pq.top()<<endl;
        return pq.top();
    }
};
