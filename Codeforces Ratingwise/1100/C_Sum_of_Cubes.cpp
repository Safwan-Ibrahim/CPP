// Created on: 2025-01-22 14:03
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
set<ll>ST;

void prec() {
    for (int i = 1; i <= 1e4; i++) {
        ST.insert(1LL * i * i * i);
    }
}

void solve() {
    ll X; cin >> X;
    
    for (auto x : ST) {
        if (ST.find(X - x) != ST.end()) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    prec();
    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
} 