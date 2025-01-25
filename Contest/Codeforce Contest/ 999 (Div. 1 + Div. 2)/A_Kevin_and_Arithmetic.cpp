// Created on: 2025-01-20 20:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x & 1) {
            odd++;
        }
        else {
            even++;
        }
    }
    
    if (even) {
        odd++;
    }
    else {
        odd--;
    }
    cout << odd << endl;

    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 