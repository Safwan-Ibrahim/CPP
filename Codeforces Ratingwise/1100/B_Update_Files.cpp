// Created on: 2025-01-30 12:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll k, n; cin >> n >> k;

    ll op = 0, done = 1;
    while(done < k) {
        done *= 2;
        op++;
    }

    ll not_yet = n - done;
    if (not_yet > 0) {
        op += (not_yet + k - 1) / k;
    }
    cout << op << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 