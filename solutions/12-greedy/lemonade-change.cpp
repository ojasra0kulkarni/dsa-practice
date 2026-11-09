#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0; // count of $5 bills owned
        int c10 = 0; // count of $10 bills owned

        for (int b : bills) {
            if (b == 5) {
                c5++;
            } else if (b == 10) {
                if (c5 == 0) return false;
                c5--;
                c10++;
            } else { // b == 20
                if (c10 > 0 && c5 > 0) { // prefer 10+5
                    c10--;
                    c5--;
                } else if (c5 >= 3) {
                    c5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
