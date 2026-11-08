#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Item{
    int v; 
    int w; 
};

bool cmp(Item a, Item b){
    double r1=(double)a.v/a.w;
    double r2=(double)b.v/b.w;
    return r1>r2;
}

class Solution{
public:
    double fractionalKnapsack(int w, Item arr[], int n){
        sort(arr, arr+n, cmp); // sort by value per weight descending

        double totalVal=0.0;
        int currW=0;

        for(int i=0;i<n;i++){
            if(currW+arr[i].w<=w){ 
                currW+=arr[i].w;
                totalVal+=arr[i].v;
            } else {
                int remW=w-currW;
                totalVal+=((double)remW/arr[i].w)*arr[i].v;
                break;
            }
        }
        return totalVal;
    }
};
