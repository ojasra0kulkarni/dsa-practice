#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {
        priority_queue<int> pq; // max heap
        for(int x : arr){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};

int main(){
    vector<int> a={7,10,4,3,20,15};
    int k=3;
    Solution sol;
    cout<<sol.kthSmallest(a,k)<<endl;
    return 0;
}
