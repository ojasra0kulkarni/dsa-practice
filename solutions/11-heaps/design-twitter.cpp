#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    int ts;
    map<int, vector<pair<int, int>>> p;
    map<int, set<int>> f;

    Twitter() {
        ts = 0;
    }

    void postTweet(int u, int id) {
        p[u].push_back({ts, id});
        ts++;
    }

    vector<int> getNewsFeed(int u) {
        priority_queue<tuple<int, int, int, int>> pq; // timestamp, tweetId, userId, tweetIdx

        set<int> chk;
        chk.insert(u);
        for(int e : f[u]) chk.insert(e);

        for(int usr : chk) {
            if(!p[usr].empty()) {
                int idx = p[usr].size() - 1;
                pq.push({p[usr][idx].first, p[usr][idx].second, usr, idx});
            }
        }

        vector<int> ans;
        while(!pq.empty() && ans.size() < 10) {
            auto [t, id, usr, idx] = pq.top();
            pq.pop();
            ans.push_back(id);

            if(idx > 0) {
                idx--;
                pq.push({p[usr][idx].first, p[usr][idx].second, usr, idx});
            }
        }
        return ans;
    }

    void follow(int fwer, int fwee) {
        f[fwer].insert(fwee);
    }

    void unfollow(int fwer, int fwee) {
        f[fwer].erase(fwee);
    }
};
