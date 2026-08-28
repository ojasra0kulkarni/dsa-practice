#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthElement(vector<int>& a, vector<int>& b, int k) {
        int n1=a.size();
        int n2=b.size();
        if(n1>n2) return findKthElement(b,a,k); // ensure a is smaller
        
        int lo=max(0,k-n2);
        int hi=min(k,n1);
        
        while(lo<=hi){
            int cut1=lo+(hi-lo)/2; // mid point for cuts in first array
            int cut2=k-cut1;
            
            int l1=(cut1==0)?INT_MIN:a[cut1-1];
            int r1=(cut1==n1)?INT_MAX:a[cut1];
            
            int l2=(cut2==0)?INT_MIN:b[cut2-1];
            int r2=(cut2==n2)?INT_MAX:b[cut2];
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2){
                hi=cut1-1;
            }
            else{ // l2>r1
                lo=cut1+1;
            }
        }
        return -1; // never reached for valid k
    }
};
