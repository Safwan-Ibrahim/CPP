// Created on: 2025-01-10 21:57
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool is_prime(int n) {
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    if (is_prime(n)) {
        cout << 1 << endl;
    }
    else if (n % 2 == 0 || is_prime(n - 2)) {
        cout << 2 << endl;
    }
    else {
        cout << 3 << endl;
    }

    return 0;
} 