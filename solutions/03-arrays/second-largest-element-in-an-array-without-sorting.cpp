#include <bits/stdc++.h>
using namespace std;

// Second Largest Element in an Array

class Solution {
public:
    int print2largest(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) {
            return -1;
        }

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            } else if (arr[i] > secondLargest && arr[i] != largest) {
                secondLargest = arr[i];
            }
        }
        
        // if secondLargest is still INT_MIN, means no distinct second largest was found
        if (secondLargest == INT_MIN) {
            return -1;
        }

        return secondLargest;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {12, 35, 1, 10, 34, 1};
    cout << "Second largest for {12, 35, 1, 10, 34, 1}: " << sol.print2largest(arr1) << endl;

    vector<int> arr2 = {10, 10, 10};
    cout << "Second largest for {10, 10, 10}: " << sol.print2largest(arr2) << endl;

    vector<int> arr3 = {1};
    cout << "Second largest for {1}: " << sol.print2largest(arr3) << endl;

    vector<int> arr4 = {5, 5, 5, 8, 8};
    cout << "Second largest for {5, 5, 5, 8, 8}: " << sol.print2largest(arr4) << endl;
    
    vector<int> arr5 = {INT_MIN, 5, 10};
    cout << "Second largest for {INT_MIN, 5, 10}: " << sol.print2largest(arr5) << endl;

    return 0;
}
