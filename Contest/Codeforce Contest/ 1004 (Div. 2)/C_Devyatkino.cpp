// Created on: 2025-02-17 03:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    for (int i = 0; i <= 7; i++) {
        int new_n = n - i;
        string sn = to_string(new_n);
        for (auto x : sn) {
            int d = x - '0';
            if (d > 7) {
                d = d - 10;
            }
            if (7 - d <= i) {
                cout << i << endl;
                return;
            }
        }
    }
    
    cout << 7 << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 