// Created on: 2025-01-22 18:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int L, R; cin >> L >> R;
    if (R == 1 && L == 1) {
        R++;
    }
    cout << R - L << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
} 