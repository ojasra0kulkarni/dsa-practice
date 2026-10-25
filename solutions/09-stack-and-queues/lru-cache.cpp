#include <bits/stdc++.h>
using namespace std;

struct Node {
    int k;
    int v;
    Node *prev;
    Node *next;
    Node(int key, int val) {
        k = key;
        v = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    int sz;
    Node *head;
    Node *tail;

    LRUCache(int capacity) {
        cap = capacity;
        sz = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *node) {
        Node *tmp = head->next;
        node->next = tmp;
        node->prev = head;
        head->next = node;
        tmp->prev = node;
    }

    void deleteNode(Node *node) {
        Node *tmpPrev = node->prev;
        Node *tmpNext = node->next;
        tmpPrev->next = tmpNext;
        tmpNext->prev = tmpPrev;
    }

    int get(int k) {
        if (mp.find(k) != mp.end()) {
            Node *node = mp[k];
            int res = node->v;
            deleteNode(node);
            addNode(node);
            return res;
        }
        return -1;
    }

    void put(int k, int v) {
        if (mp.find(k) != mp.end()) {
            Node *node = mp[k];
            node->v = v;
            deleteNode(node);
            addNode(node);
        } else {
            Node *newNode = new Node(k, v);
            mp[k] = newNode;
            addNode(newNode);
            sz++;
            if (sz > cap) {
                Node *lru = tail->prev;
                deleteNode(lru);
                mp.erase(lru->k);
                delete lru;
                sz--;
            }
        }
    }
};
