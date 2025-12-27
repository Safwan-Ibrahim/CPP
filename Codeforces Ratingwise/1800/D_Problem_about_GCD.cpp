// Created on: 2025-12-03 10:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    ll l, r, g; cin >> l >> r >> g;

    l = (l + g - 1) / g, r = r / g;
    for (ll d = r - l; d >= 0; d--) {
        for (ll x = l; x + d <= r; x++) {
            if (__gcd(x, (x + d)) == 1) {
                cout << g * x << " " << g * (x + d) << endl; return;
            }
        }
    }

    cout << "-1 -1\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 