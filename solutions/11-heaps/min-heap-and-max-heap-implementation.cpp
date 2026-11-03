#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> v;
public:
    MinHeap() {}
    void push(int x) {
        v.push_back(x);
        int idx=v.size()-1;
        while(idx>0&&v[(idx-1)/2]>v[idx]){ // parent index
            swap(v[idx],v[(idx-1)/2]);
            idx=(idx-1)/2;
        }
    }
    void pop() {
        if(v.empty()) return;
        swap(v[0],v.back());
        v.pop_back();
        int n=v.size();
        int curr=0;
        while(true){
            int l=2*curr+1;
            int r=2*curr+2;
            int s=curr;
            if(l<n&&v[l]<v[s]) s=l;
            if(r<n&&v[r]<v[s]) s=r;
            if(s==curr) break;
            swap(v[curr],v[s]);
            curr=s;
        }
    }
    int top() {
        return v[0];
    }
    int size() {
        return v.size();
    }
    bool empty() {
        return v.empty();
    }
};

class MaxHeap {
    vector<int> v;
public:
    MaxHeap() {}
    void push(int x) {
        v.push_back(x);
        int idx=v.size()-1;
        while(idx>0&&v[(idx-1)/2]<v[idx]){
            swap(v[idx],v[(idx-1)/2]);
            idx=(idx-1)/2;
        }
    }
    void pop() {
        if(v.empty()) return;
        swap(v[0],v.back());
        v.pop_back();
        int n=v.size();
        int curr=0;
        while(true){
            int l=2*curr+1;
            int r=2*curr+2;
            int b=curr;
            if(l<n&&v[l]>v[b]) b=l;
            if(r<n&&v[r]>v[b]) b=r;
            if(b==curr) break;
            swap(v[curr],v[b]);
            curr=b;
        }
    }
    int top() {
        return v[0];
    }
    int size() {
        return v.size();
    }
    bool empty() {
        return v.empty();
    }
};
