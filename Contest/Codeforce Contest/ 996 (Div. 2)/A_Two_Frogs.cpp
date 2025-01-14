// Created on: 2025-01-14 11:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if ((abs(a - b) - 1) % 2 == 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 