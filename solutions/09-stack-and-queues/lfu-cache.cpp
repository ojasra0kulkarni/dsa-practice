#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int _cap, _sz, _mnF;
    map<int, pair<int, int>> kf; 
    map<int, list<int>> freqL; 
    map<int, list<int>::iterator> itMp; 

    void updFreq(int k) {
        int oldF = kf[k].second;
        freqL[oldF].erase(itMp[k]);

        if (freqL[oldF].empty() && oldF == _mnF) _mnF++; // update min freq if list empty

        kf[k].second++;
        freqL[kf[k].second].push_back(k);
        itMp[k] = --freqL[kf[k].second].end();
    }

public:
    LFUCache(int capacity) {
        _cap = capacity;
        _sz = 0;
        _mnF = 0;
    }

    int get(int k) {
        if (_cap == 0) return -1;
        if (!kf.count(k)) return -1;

        int temp = kf[k].first;
        updFreq(k);
        // cout<<temp<<endl;
        return temp;
    }

    void put(int k, int val) {
        if (_cap == 0) return;

        if (kf.count(k)) {
            kf[k].first = val;
            updFreq(k);
            return;
        }

        if (_sz == _cap) {
            int temp = freqL[_mnF].front();
            freqL[_mnF].pop_front();
            kf.erase(temp);
            itMp.erase(temp);
            _sz--;
        }

        _mnF = 1;
        kf[k] = {val, 1};
        freqL[1].push_back(k);
        itMp[k] = --freqL[1].end();
        _sz++;
    }
};
