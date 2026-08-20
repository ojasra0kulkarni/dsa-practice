#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();

        if(n==1) return arr[0];
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];

        int l=1, r=n-2;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];

            if(mid%2==0){ // mid is even
                if(arr[mid]==arr[mid+1]) l=mid+2;
                else r=mid-1;
            }
            else { // mid is odd
                if(arr[mid]==arr[mid-1]) l=mid+1;
                else r=mid-1;
            }
        }
        return -1; 
    }
};

int main() {
    Solution sol;
    vector<int> a={1,1,2,3,3,4,4,8,8};
    cout<<sol.singleNonDuplicate(a)<<endl;
    return 0;
}
