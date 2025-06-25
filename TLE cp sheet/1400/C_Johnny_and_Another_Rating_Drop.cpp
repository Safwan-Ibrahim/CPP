// Created on: 2025-05-04 16:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

long long n;

void Try() {
    cin >> n;
    long long ans = 0;
    for (int k = 0; k < 63; k++) {
        if (n >> k & 1) {
            ans += (1LL << (k + 1)) - 1;
        }
    }
    cout << ans << endl;
    
}

void Try2() {
    cin >> n;
    cout << (n << 1) - __builtin_popcountll(n) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try2();
    }
    return 0;
} 