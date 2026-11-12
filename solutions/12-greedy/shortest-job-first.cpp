#include <bits/stdc++.h>
using namespace std;

struct J {
    int id;
    int a;
    int b;
};

bool comp(const J& x, const J& y) {
    if(x.a!=y.a) return x.a<y.a;
    return x.b<y.b;
}

class Solution {
public:
    double avgWT(vector<vector<int>>& in) {
        int n=in.size();
        vector<J> js(n);
        for(int i=0;i<n;i++){
            js[i].id=i;
            js[i].a=in[i][0];
            js[i].b=in[i][1];
        }

        sort(js.begin(), js.end(), comp);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // pq stores {burst, index in sorted js}

        int curr=0;
        int jdx=0;
        long long s=0;
        int c=0;

        while(c<n){
            while(jdx<n && js[jdx].a<=curr){
                pq.push({js[jdx].b, jdx});
                jdx++;
            }

            if(pq.empty()){
                if(jdx<n) curr=js[jdx].a; // advance time to next arrival
                else break; // all jobs processed
            } else {
                pair<int, int> p=pq.top();
                pq.pop();

                int idx=p.second;
                int st=curr;
                int ct=curr+js[idx].b;
                int wt=st-js[idx].a;

                if(wt<0) wt=0;

                s+=wt;
                curr=ct;
                c++;
            }
        }
        return (double)s/n;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> jobs={{0,6},{1,8},{2,7},{3,3}};
    cout<<sol.avgWT(jobs)<<endl;
    return 0;
}
