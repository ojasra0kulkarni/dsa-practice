#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n=mat.size();
        if(n==0)return false;
        int m=mat[0].size();
        if(m==0)return false;

        int lo=0;
        int hi=n*m-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2; // mid overflow
            int r=mid/m;
            int c=mid%m;

            if(mat[r][c]==x){
                return true;
            }else if(mat[r][c]<x){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return false;
    }
};
