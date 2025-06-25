// Created on: 2025-06-20 16:28
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

int power(int x, int n, int m) {
    int ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        n >>= 1;
        x = 1LL * x * x % m;
    }
    return ans;
}

void Try() {
    int l, r, k; cin >> l >> r >> k;
    if (k > 9) {
        cout << 0 << endl; return;
    }

    int x = (10 + k - 1) / k;
    int ans = (power(x, r, mod) - power(x, l, mod) + mod) % mod;
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 