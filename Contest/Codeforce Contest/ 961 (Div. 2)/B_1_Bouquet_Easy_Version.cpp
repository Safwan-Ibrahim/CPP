// Created on: 2025-02-14 22:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; ll k; cin >> n >> k;
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[x]++;
    }

    ll mx = 0;
    ll prev = 0;
    for (auto [x, y] : Mp) {;
        if (Mp.find(x - 1) != Mp.end()) {
            for (int i = 0; i <= y && 1LL * i * x <= k; i++) {
                ll highest_prev = (k - 1LL * i * x) / (x - 1);
                mx = max(mx, 1LL * i * x + 1LL * min(highest_prev, prev) * (x - 1));
            }
        }
        else {
            ll highest = k / x;
            mx = max(mx, min(1LL * y * x, highest * x)); 
        }
        prev = y;
    }
    
    cout << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 