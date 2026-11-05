#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        int n=arr.size();
        if(n%k!=0) return false;

        map<int, int> mp;
        for(int x:arr) mp[x]++;

        for(auto it=mp.begin(); it!=mp.end(); it++){
            int x=it->first;
            int cnt=it->second;

            if(cnt==0) continue;

            for(int i=0; i<k; i++){
                if(mp.find(x+i)==mp.end() || mp[x+i]<cnt){
                    return false;
                }
                mp[x+i]-=cnt;
            }
        }
        return true;
    }
};

int main(){
    vector<int> a={1,2,3,6,2,3,4,7,8};
    int k=3;
    Solution s;
    cout<<s.isNStraightHand(a,k)<<endl;
    return 0;
}
