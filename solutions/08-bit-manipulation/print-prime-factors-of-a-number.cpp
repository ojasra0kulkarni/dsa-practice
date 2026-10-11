#include <bits/stdc++.h>
using namespace std;

void printPrimeFactors(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 1) {
        cout << n << " ";
    }
    
}
