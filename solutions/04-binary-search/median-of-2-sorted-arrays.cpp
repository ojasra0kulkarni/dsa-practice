#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size() > b.size()) return findMedianSortedArrays(b, a); // ensure a is smaller or equal
        
        int n1 = a.size();
        int n2 = b.size();
        
        int lo=0, hi=n1;
        
        while(lo<=hi){
            int cut1 = (lo+hi)/2;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int l1 = (cut1==0) ? INT_MIN : a[cut1-1];
            int r1 = (cut1==n1) ? INT_MAX : a[cut1];
            
            int l2 = (cut2==0) ? INT_MIN : b[cut2-1];
            int r2 = (cut2==n2) ? INT_MAX : b[cut2];
            
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2 == 0){
                    return (double)(max(l1,l2) + min(r1,r2))/2.0;
                } else {
                    return (double)max(l1,l2);
                }
            } else if (l1 > r2){
                hi = cut1-1;
            } else {
                lo = cut1+1;
            }
        }
        return 0.0;
    }
};
