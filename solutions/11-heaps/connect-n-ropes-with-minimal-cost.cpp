#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    ll minCost(vector<int>& arr) {
        priority_queue<ll, vector<ll>, greater<ll>> pq; // min heap
        for(int x:arr) pq.push(x);
        
        ll cost=0;
        while(pq.size()>1){
            ll x=pq.top();pq.pop();
            ll y=pq.top();pq.pop();
            ll sum=x+y;
            cost+=sum;
            pq.push(sum);
        }
        return cost;
    }
};

int main() {
    vector<int> arr={4,3,2,6};
    Solution sol;
    cout<<sol.minCost(arr)<<endl;
    return 0;
}
