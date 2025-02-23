// Created on: 2025-02-08 01:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    
    int pow_n = 1;
    int ans = 0;
    while(k > 0) {
        if (k & 1) {
            ans = (1LL * ans + pow_n) % M;
        }
        k >>= 1;
        pow_n = 1LL * pow_n * n % M;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 