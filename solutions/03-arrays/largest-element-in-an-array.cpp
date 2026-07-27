#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Largest Element in an Array
int largestElement(vector<int> &arr) {
    // tricky part: assume array is not empty for this problem
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 2};
    cout << "Largest element is: " << largestElement(nums) << endl; // Expect 5
    vector<int> single = {7};
    cout << "Largest element is: " << largestElement(single) << endl; // Expect 7
    vector<int> negs = {-10, -5, -20};
    cout << "Largest element is: " << largestElement(negs) << endl; // Expect -5
    return 0;
}
