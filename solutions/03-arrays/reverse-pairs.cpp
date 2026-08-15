#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(vector<int> &arr, int lo, int mid, int hi) {
        int cnt = 0;
        int j = mid + 1;
        for (int i = lo; i <= mid; i++) {
            while (j <= hi && arr[i] > 2LL * arr[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        vector<int> tmp;
        int left = lo, right = mid + 1;
        while (left <= mid && right <= hi) {
            if (arr[left] <= arr[right]) {
                tmp.push_back(arr[left++]);
            } else {
                tmp.push_back(arr[right++]);
            }
        }

        while (left <= mid) tmp.push_back(arr[left++]);
        while (right <= hi) tmp.push_back(arr[right++]);

        for (int i = lo; i <= hi; i++) arr[i] = tmp[i - lo];
        return cnt;
    }

    int mergeSort(vector<int> &arr, int lo, int hi) {
        if (lo >= hi) return 0;
        int mid = lo + (hi - lo) / 2;
        int cnt = mergeSort(arr, lo, mid);
        cnt += mergeSort(arr, mid + 1, hi);
        cnt += merge(arr, lo, mid, hi);
        return cnt;
    }

    int reversePairs(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    vector<int> a = {5,4,3,2,1};
    Solution sol;
    cout << sol.reversePairs(a) << endl;
    return 0;
}
