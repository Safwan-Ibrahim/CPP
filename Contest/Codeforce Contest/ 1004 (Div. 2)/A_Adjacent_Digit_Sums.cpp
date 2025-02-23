// Created on: 2025-02-11 20:42
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int x, y; cin >> x >> y;

    int nine = x / 9;
    if (y == x + 1) {
        cout << "Yes\n";
    }
    else if (x > y && (x - y + 1) % 9 == 0 && (x - y + 1) / 9 <= nine) {
        cout << "Yes\n";
    }
    else {
        cout  << "No\n";
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