#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;

        map<int,int> mp; // fruit type -> count
        int l=0,mx=0;

        for(int r=0;r<n;r++){
            mp[arr[r]]++;
            while(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]); // remove type if count is zero
                l++;
            }
            mx=max(mx,r-l+1);
        }
        return mx;
    }
};

int main(){
    vector<int> a={1,2,1};
    Solution sol;
    cout<<sol.totalFruit(a)<<endl;
    return 0;
}
