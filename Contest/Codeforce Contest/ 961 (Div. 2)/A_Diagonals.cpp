// Created on: 2025-02-14 22:09
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;
    int dg = (n - 1) * 2 + 1;
    int mx = n;
    int ans = 0;
    bool one_done = true;
    while(k) {
        k -= min(mx, k);
        if (one_done) {
            mx--;
        }
        one_done ^= 1;
        ans++;
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 