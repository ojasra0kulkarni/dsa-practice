#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Largest Element in an Array
int largestElement(vector<int> arr) {
    int max_val = arr[0]; // start max with first element
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int main() {
    vector<int> arr = {4, 7, 8, 6, 7, 1};
    cout << largestElement(arr) << endl; // expect 8
    return 0;
}
