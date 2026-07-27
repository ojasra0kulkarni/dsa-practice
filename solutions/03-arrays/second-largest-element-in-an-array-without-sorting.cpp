#include <bits/stdc++.h>
using namespace std;

// second largest element in an array
int findSecondLargest(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) { // edge case: array must have at least two elements for a distinct second largest
        return -1; // common for problems to return -1 or throw exception
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int x : arr) { // using range-based for loop, feels more modern/confident student
        if (x > largest) {
            secondLargest = largest;
            largest = x;
        } else if (x < largest && x > secondLargest) { // tricky part: x must be less than largest to be a *distinct* second largest
            secondLargest = x;
        }
    }
    
    // if secondLargest is still INT_MIN, it means all elements were the same (e.g., {5,5,5})
    // or only one unique element existed. In such cases, there's no distinct second largest.
    if (secondLargest == INT_MIN) {
        return -1; 
    }

    return secondLargest;
}

int main() {
    // test cases
    vector<int> arr1 = {3, 1, 4, 1, 5, 9, 2, 6};
    cout << "Second largest in {3, 1, 4, 1, 5, 9, 2, 6}: " << findSecondLargest(arr1) << endl; // Expected: 6

    vector<int> arr2 = {10, 5, 8, 20};
    cout << "Second largest in {10, 5, 8, 20}: " << findSecondLargest(arr2) << endl; // Expected: 10

    vector<int> arr3 = {5, 5, 5};
    cout << "Second largest in {5, 5, 5}: " << findSecondLargest(arr3) << endl; // Expected: -1

    vector<int> arr4 = {1};
    cout << "Second largest in {1}: " << findSecondLargest(arr4) << endl; // Expected: -1

    vector<int> arr5 = {1, 2, 3, 4, 5};
    cout << "Second largest in {1, 2, 3, 4, 5}: " << findSecondLargest(arr5) << endl; // Expected: 4
    
    vector<int> arr6 = {7,7,7,7,7,7,7,7,8};
    cout << "Second largest in {7,7,7,7,7,7,7,7,8}: " << findSecondLargest(arr6) << endl; // Expected: 7

    return 0;
}
