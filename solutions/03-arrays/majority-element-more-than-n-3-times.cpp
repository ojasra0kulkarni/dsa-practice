#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
        int c1=-1,c2=-1; // candidates
        int cnt1=0,cnt2=0;

        for(int i=0;i<n;i++){
            if(arr[i]==c1) cnt1++;
            else if(arr[i]==c2) cnt2++;
            else if(cnt1==0){
                c1=arr[i];
                cnt1=1;
            }
            else if(cnt2==0){
                c2=arr[i];
                cnt2=1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        cnt1=0;cnt2=0; // reset counts
        for(int x:arr){
            if(x==c1) cnt1++;
            if(x==c2) cnt2++;
        }

        if(cnt1>n/3) ans.push_back(c1);
        if(cnt2>n/3 && c1!=c2) ans.push_back(c2); // avoid duplicate if candidates same

        return ans;
    }
};
