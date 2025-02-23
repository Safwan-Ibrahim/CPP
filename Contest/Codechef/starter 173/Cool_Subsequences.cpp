// Created on: 2025-02-12 20:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[x]++;
    }


    for (auto [x, y] : Mp) {
        if (y > 1) {
            cout << 1 << endl;
            cout << x << endl;
            return;
        }
    }
    
    cout << -1 << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 